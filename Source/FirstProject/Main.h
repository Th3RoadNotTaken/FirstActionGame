// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Main.generated.h"

UENUM(BlueprintType) // BlueprintType same as Blueprintable
enum class EMovementStatus : uint8
{
	EMS_Normal UMETA(DisplayName = "Normal"),  // If we are marking the enum class and UENUM, we also need to mark the enum constants with UMETA
	EMS_Sprinting UMETA(DisplayName = "Sprinting"),
	EMS_Dead UMETA(DisplayName = "Dead"),

	EMS_Max UMETA(DisplayName = "DefaultMax")
};

UENUM(BlueprintType)
enum class EStaminaStatus : uint8
{
	ESS_Normal UMETA(DisplayName = "Normal"),
	ESS_BelowMinimum UMETA(DisplayName = "BelowMinimum"),
	ESS_Exhausted UMETA(DisplayName = "Exhausted"),
	ESS_ExhaustedRecovering UMETA(DisplayName = "ExhaustedRecovering"),

	ESS_MAX UMETA(DisplayName = "DefaultMax")
};

UCLASS()
class FIRSTPROJECT_API AMain : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMain();

	UPROPERTY(EditDefaultsOnly, Category = "SavedData")
	TSubclassOf<class AItemStorage> WeaponStorage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	class UParticleSystem* HitParticles;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	class USoundCue* HitSound;

	TArray<FVector> PickupLocations;

	UFUNCTION(BlueprintCallable)
	void ShowPickupLocations();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enums")
	EMovementStatus MovementStatus;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Enums")
	EStaminaStatus StaminaStatus;

	FORCEINLINE void SetStaminaStatus(EStaminaStatus Status) { StaminaStatus = Status; }

	/** The amount by which the stamina will drain per second */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float StaminaDrainRate;
	/** The minimum stamina value after which the stamina HUD colour will update */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MinSprintStamina;
	/** The amounnt by which the stamina will recover per second */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float StaminaRecoveryRate;

	/** Creating interpolation for the player towards the enemy if they are close enough */
	float InterpSpeed;
	bool bInterpToEnemy;
	void SetInterpToEnemy(bool Interp);
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	class AEnemy* CombatTarget;
	FORCEINLINE void SetCombatTarget(AEnemy* Target) { CombatTarget = Target; }
	FRotator GetLookAtRotationYaw(FVector Target);

	/** Boolean to enable or disable the enemy health bar*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	bool bHasCombatTarget;
	FORCEINLINE void SetHasCombatTarget(bool HasTarget) { bHasCombatTarget = HasTarget; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Controller")
	class AMainPlayerController* MainPlayerController;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Combat")
	FVector CombatTargetLocation;

	/** Set movement status and running speed */
	void SetMovementStatus(EMovementStatus Status);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Running")
	float RunningSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Running")
	float SprintingSpeed;

	bool bShiftKeyDown;

	/** Press down to enable sprinting */
	void ShiftKeyDown();

	/** Release to stop sprinting */
	void ShiftKeyUp();

	/** Camera boom positioning the camera behind the player */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess="true"))
	class USpringArmComponent* CameraBoom;

	/** Follow the player */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	/** Base turn rates to scale turning functions for the camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate;

	/**
	* 
	* 
	* Player Stats
	* 
	*/

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerStats")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
	float Health;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "PlayerStats")
	float MaxStamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
	float Stamina;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerStats")
	int32 Coins;

	/** Function to decrease character health if damaged */
	void DecrementHealth(float Damage);

	/** TakeDamage function is part of the Actor class which we are overriding here */
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	/** Function when the character reaches 0 health */
	void Die();

	virtual void Jump() override;

	UFUNCTION(BlueprintCallable)
	void IncrementCoins(int32 CoinCount);
	UFUNCTION(BlueprintCallable)
	void IncrementHealth(float Amount);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	class UBoxComponent* CombatCollisionLeft;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Combat")
	class UBoxComponent* CombatCollisionRight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	USoundCue* PunchSound;

	/** Boolean to trigger collision based on which arm is attacking */
	bool bFirstPunchAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item | Combat")
	TSubclassOf<UDamageType> DamageTypeClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Item | Combat" )
	float UnarmedDamage;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Called for forward/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);

	bool bMovingForward;
	bool bMovingRight;

	bool CanMove(float Value);

	/** Called via input to turn at a given rate */
	/* @param Rate - This is a noramlized rate, i.e 1.0 means 100% of desired turn rate
	*/
	void TurnAtRate(float Rate);

	/** Called via input to look up/down at a given rate */
	/* @param Rate - This is a noramlized rate, i.e 1.0 means 100% of desired look up/down rate
	*/
	void LookUpAtRate(float Rate);

	bool bLMBDown;

	void LMBDown();

	void LMBUp();

	bool bESCDown;

	void ESCDown();

	void ESCUp();

	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Items")
	class AWeapon* EquippedWeapon;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
	class AItem* ActiveOverlappingItem;

	void SetEquippedWeapon(AWeapon* WeaponToSet);
	FORCEINLINE AWeapon* GetEquippedWeapon() { return EquippedWeapon; }
	FORCEINLINE void SetActiveOverlappingItem(AItem* Item) { ActiveOverlappingItem = Item; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Anims")
	bool bAttacking;

	void Attack();

	void UnarmedAttack();

	UFUNCTION(BlueprintCallable)
	void AttackEnd();

	UFUNCTION(BlueprintCallable)
	void UnarmedAttackEnd();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Anims")
	class UAnimMontage* CombatMontage;

	UFUNCTION(BlueprintCallable)
	void PlaySwingSound();

	UFUNCTION()
	void CombatOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void CombatOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable)
	void ActivatePunchCollision();

	UFUNCTION(BlueprintCallable)
	void DeactivatePunchCollision();

	UFUNCTION(BlueprintCallable)
	void DeathEnd();

	/** If the player is overlapping with multiple targets and he/she kills one... */
	/** ...then the combat target should be set to the next alive target */
	void UpdateCombatTarget();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat")
	TSubclassOf<AEnemy> EnemyFilter;

	void SwitchLevel(FName LevelName);

	UFUNCTION(BlueprintCallable)
	void SaveGame();

	UFUNCTION(BlueprintCallable)
	void LoadGame(bool SetPosition);

	UFUNCTION(BlueprintCallable)
	void LoadGameNoSwitch();
};
