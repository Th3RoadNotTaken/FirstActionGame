// Fill out your copyright notice in the Description page of Project Settings.


#include "Explosive.h"
#include "Main.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Particles/ParticleSystemComponent.h"
#include "Engine/World.h"
#include "Enemy.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

AExplosive::AExplosive()
{
	Damage = 15.f;
	bAlreadyOverlapped = false;
	bTimeBomb = false;

	BombTickingParticles = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("BombTickingParticles"));
	BombTickingParticles->SetupAttachment(GetRootComponent());
}

void AExplosive::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
	if (OtherActor)
	{
		AMain* Main = Cast<AMain>(OtherActor); // If the actor is AMain character then Main variable will hold it otherwise it will hold null
		AEnemy* Enemy = Cast<AEnemy>(OtherActor);

		if (Main || Enemy)
		{
			FTimerHandle TimerHandle;
			FTimerDelegate TimerDelegate = FTimerDelegate::CreateUObject(this, &AExplosive::ExplosionDamage); // Required when setting a timer which calls a function with parameters. Can give parameters after a comma

			if (bTimeBomb && bAlreadyOverlapped == false)
			{
				bAlreadyOverlapped = true;
				if (OverlapSound)
				{
					UGameplayStatics::PlaySound2D(this, OverlapSound);
				}
				if (BombTickingParticles)
				{
					BombTickingParticles->Activate();
				}
				GetWorldTimerManager().SetTimer(TimerHandle, TimerDelegate, 2.f, false);
			}
			else if(bTimeBomb==false)
			{
				ExplosionDamage();
			}
		}
	}
}

void AExplosive::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	//UE_LOG(LogTemp, Warning, TEXT("Explosive::Overlap Ends..."));
}

void AExplosive::ExplosionDamage()
{
	if (BombTickingParticles)
	{
		BombTickingParticles->Deactivate();
	}

	if (OverlapParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), OverlapParticles, GetActorLocation(), FRotator(0.f), true);
	}

	if (ExplosionSound)
	{
		UGameplayStatics::PlaySound2D(this, ExplosionSound);
	}

	TArray<AActor*> OverlappingActors;
	TSubclassOf<ACharacter> CharacterFilter;
	GetOverlappingActors(OverlappingActors, CharacterFilter);

	for (auto Char : OverlappingActors)
	{
		AMain* Main = Cast<AMain>(Char);
		AEnemy* Enemy = Cast<AEnemy>(Char);

		if (Main)
		{
			UGameplayStatics::ApplyDamage(Main, Damage, nullptr, this, DamageTypeClass);
		}
		if (Enemy)
		{
			UGameplayStatics::ApplyDamage(Enemy, Damage, nullptr, this, DamageTypeClass);
		}
	}
	Destroy();
}