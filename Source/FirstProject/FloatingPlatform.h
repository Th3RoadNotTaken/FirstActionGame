// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

UCLASS()
class FIRSTPROJECT_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingPlatform();

	/** Mesh for the floating platform */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Platform)
	class UStaticMeshComponent* Mesh;

	/** Defining start and end points for the floating platform */
	UPROPERTY(EditAnywhere, Category=Platform)
	FVector StartPoint;

	UPROPERTY(EditAnywhere, Category = Platform, meta = (MakeEditWidget = "true")) // MakeEditWidget - Visualization widget to manipulate in the editor
	FVector EndPoint;

	/** Speed for the interpolation from start to end point of the platform */
	UPROPERTY(EditAnywhere, Category = Platform)
	float InterpSpeed;

	/** Time for interpolation timer */
	UPROPERTY(EditAnywhere, Category = Platform)
	float InterpTime;

	/** Timer for the platform once it reaches either of the end points */
	FTimerHandle InterpTimer;

	UPROPERTY(EditAnywhere, Category = Platform)
	bool bInterping;

	float Distance;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	/** To toggle bInterping */
	void ToggleInterping();

	void SwapVectors(FVector& Vec1, FVector& Vec2);
};
