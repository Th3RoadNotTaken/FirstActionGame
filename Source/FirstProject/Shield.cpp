// Fill out your copyright notice in the Description page of Project Settings.


#include "Shield.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Main.h"
#include "Enemy.h"
#include "Components/SphereComponent.h"

AShield::AShield()
{

	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(GetRootComponent());

	CombatCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("CombatCollision"));
	CombatCollision->SetupAttachment(GetRootComponent());

	bShieldParticles = false;
	ShieldState = EShieldState::EWS_Pickup;

	Health = 100.f;
	MaxHealth = 100.f;
}

void AShield::BeginPlay()
{
	Super::BeginPlay();

	CombatCollision->OnComponentBeginOverlap.AddDynamic(this, &AShield::ShieldOnOverlapBegin);
	CombatCollision->OnComponentEndOverlap.AddDynamic(this, &AShield::ShieldOnOverlapEnd);

	CombatCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CombatCollision->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	CombatCollision->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CombatCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_WorldDynamic, ECollisionResponse::ECR_Overlap);
}

void AShield::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlapBegin(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (ShieldState == EShieldState::EWS_Pickup && OtherActor)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			Main->SetActiveOverlappingItem(this);
		}
	}
}

void AShield::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	Super::OnOverlapEnd(OverlappedComponent, OtherActor, OtherComp, OtherBodyIndex);

	if (OtherActor)
	{
		AMain* Main = Cast<AMain>(OtherActor);
		if (Main)
		{
			Main->SetActiveOverlappingItem(nullptr);
		}
	}
}

void AShield::ShieldOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Overlap Begins"))
	if (OtherActor)
	{
		AEnemy* Enemy = Cast<AEnemy>(OtherActor);
		if (Enemy)
		{
			Enemy->CombatCollision->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);
		}
	}
}

void AShield::ShieldOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}

void AShield::Equip(AMain* Character)
{
	if (Character)
	{
		// Camera won't zoom in if the sword is in the way
		SkeletalMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Camera, ECollisionResponse::ECR_Ignore);
		SkeletalMesh->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Ignore);

		SkeletalMesh->SetSimulatePhysics(false);

		const USkeletalMeshSocket* LeftHandSocket = Character->GetMesh()->GetSocketByName("LeftHandSocket");

		if (LeftHandSocket)
		{
			LeftHandSocket->AttachActor(this, Character->GetMesh());
			bRotate = false;

			Character->SetEquippedShield(this);
			Character->SetActiveOverlappingItem(nullptr);
		}
		CollisionVolume->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void AShield::ActivateCollision()
{
	CombatCollision->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void AShield::DeactivateCollision()
{
	CombatCollision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

float AShield::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	if (Health - DamageAmount <= 0)
	{
		Health = 0;
		DestroyShield();
	}
	else
	{
		Health -= DamageAmount;
	}
	return DamageAmount;
}

void AShield::DestroyShield()
{
	AActor* Actor = GetAttachParentActor();
	AMain* Main = Cast<AMain>(Actor);
	if (Main)
	{
		Main->SetEquippedShield(nullptr);
		Main->bHasShieldEquipped = false;
		Destroy();
	}
}