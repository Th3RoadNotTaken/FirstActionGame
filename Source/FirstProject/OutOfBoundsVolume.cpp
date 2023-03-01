// Fill out your copyright notice in the Description page of Project Settings.


#include "OutOfBoundsVolume.h"
#include "Components/BoxComponent.h"
#include "Main.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AOutOfBoundsVolume::AOutOfBoundsVolume()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	OutOfBoundsComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("OutOfBoundsComponent"));
	SetRootComponent(OutOfBoundsComponent);
}

// Called when the game starts or when spawned
void AOutOfBoundsVolume::BeginPlay()
{
	Super::BeginPlay();
	OutOfBoundsComponent->OnComponentBeginOverlap.AddDynamic(this, &AOutOfBoundsVolume::OnOverlapBegin);
}

// Called every frame
void AOutOfBoundsVolume::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AOutOfBoundsVolume::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		UGameplayStatics::OpenLevel(GetWorld(), FName(*GetWorld()->GetName()), false);
	}
}