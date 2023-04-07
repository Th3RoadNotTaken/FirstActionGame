// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloorSwitch.generated.h"

UCLASS()
class FIRSTPROJECT_API AFloorSwitch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloorSwitch();

	/** Overlap volume for functionality to be triggered */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = FloorSwitch)
	class UBoxComponent* TriggerBox;

	/** The switch for the character to step on */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = FloorSwitch)
	class UStaticMeshComponent* FloorSwitch;

	/** Door to open when floor switch is stepped on */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = FloorSwitch)
	UStaticMeshComponent* Door;

	/** Initial location for the door */
	UPROPERTY(BlueprintReadWrite, Category = FloorSwitch)
	FVector InitialDoorLocation;

	/** Initial rotation for the door */
	UPROPERTY(BlueprintReadWrite, Category = FloorSwitch)
	FRotator InitialDoorRotation;

	/** Initial location for the floor switch */
	UPROPERTY(BlueprintReadWrite, Category = FloorSwitch)
	FVector InitialSwitchLocation;

	/** Defining a timer handle for when the door should drop down */
	/** once the character is no longer overlapping with the switch */
	FTimerHandle SwitchHandle;

	/** Timer count*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FloorSwitch)
	float SwitchTime;

	/** Calling this function once the timer ends*/
	void CloseDoor();

	bool bCharacterOnSwitch;

	/** Boolean to check if a door needs to open only after a certain number of enemies have been defeated */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FloorSwitch)
	bool bConditionalDoor;
	/** This integer represents the number of enemies that will remain after defeating enemies of a particular section(which allows the player to open a certain door) */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = FloorSwitch)
	int32 RemainingEnemies;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch)  // BlueprintImplementableEvent means you can implement the functionality in the blueprint
	void RaiseDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch)  
	void LowerDoor();

	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch)  
	void RaiseFloorSwitch();

	UFUNCTION(BlueprintImplementableEvent, Category = FloorSwitch) 
	void LowerFloorSwitch();

	UFUNCTION(BlueprintCallable, Category = FloorSwitch)
	void UpdateDoorLocation(float Z);

	UFUNCTION(BlueprintCallable, Category = FloorSwitch)
	void UpdateDoorRotation(float Z);

	UFUNCTION(BlueprintCallable, Category = FloorSwitch)
	void UpdateFloorSwitchLocation(float Z);

	bool AllEnemiesDead();
};
