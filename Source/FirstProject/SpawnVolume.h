// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

UCLASS()
class FIRSTPROJECT_API ASpawnVolume : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpawnVolume();

	/** We will spawn creatures randomly in this box */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Spawning)
	class UBoxComponent* SpawningBox;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category=Spawning)
	TSubclassOf<AActor> Actor_1; // Technically getting a BP of a variable (Here we are getting an Actor)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawning)
	TSubclassOf<AActor> Actor_2; 
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawning)
	TSubclassOf<AActor> Actor_3;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Spawning)
	TSubclassOf<AActor> Actor_4;

	TArray<TSubclassOf<AActor>> SpawnArray;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintPure, Category=Spawning)  // BlueprintPure means that if we call this function from a BP, we will only have the return value from it
	FVector GetSpawnPoint();

	UFUNCTION(BlueprintPure, Category = Spawning)  
	TSubclassOf<AActor> GetSpawnActor();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category=Spawning) // BlueprintNativeEvent means that we will script this out both in C++ and BP
	void SpawnOurActor(UClass* ToSpawn, const FVector& Location);
};
