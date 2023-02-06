// Fill out your copyright notice in the Description page of Project Settings.


#include "Main.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Engine/World.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Weapon.h" 
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/BoxComponent.h"
#include "Engine/SkeletalMeshSocket.h"
#include "Enemy.h"
#include "Kismet/KismetMathLibrary.h"
#include "MainPlayerController.h"

// Sets default values
AMain::AMain()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create camera boom (Pulls towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(GetRootComponent());
	CameraBoom->TargetArmLength = 600.f; // Camera follows at this distance
	CameraBoom->bUsePawnControlRotation = true; // Rotate arm based on controller

	// Set size for collision capsule
	GetCapsuleComponent()->SetCapsuleSize(35.f, 102.f);

	// Create follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	// Attach the camera to the end of the boom and let the boom adjust to match 
	// the controller orientation
	FollowCamera->bUsePawnControlRotation = false;

	// Set our turn rates for input
	BaseTurnRate = 65.f;
	BaseLookUpRate = 65.f;

	// Do not rotate when the controller rotates
	// Let that just affect the camera
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 640.f, 0.0f); // ... at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 450.f;
	GetCharacterMovement()->AirControl = 0.4f;

	// Default values for player stats
	MaxHealth = 100.f;
	Health = 65.f;
	MaxStamina = 150.f;
	Stamina = 120.f;
	Coins = 0;
	UnarmedDamage = 15.f; // Damage that the player's punch applies

	RunningSpeed = 650.f;
	SprintingSpeed = 950.f;
	bShiftKeyDown = false;

	// Initialize Enum variables
	MovementStatus = EMovementStatus::EMS_Normal;
	StaminaStatus = EStaminaStatus::ESS_Normal;

	StaminaDrainRate = 20.f;
	MinSprintStamina = 60.f;
	StaminaRecoveryRate = 25.f;

	bLMBDown = false;

	CombatCollisionLeft = CreateDefaultSubobject<UBoxComponent>(TEXT("CombatCollisionLeft"));
	CombatCollisionRight = CreateDefaultSubobject<UBoxComponent>(TEXT("CombatCollisionRight"));
	CombatCollisionLeft->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("PunchSocketLeft"));
	CombatCollisionRight->AttachToComponent(GetMesh(), FAttachmentTransformRules::SnapToTargetIncludingScale, FName("PunchSocketRight"));

	InterpSpeed = 15.f;
	bInterpToEnemy = false;

	bHasCombatTarget = false;

	bMovingForward = false;
	bMovingRight = false;
}

// Called when the game starts or when spawned
void AMain::BeginPlay()
{
	Super::BeginPlay();

	CombatCollisionLeft->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CombatCollisionLeft->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	CombatCollisionLeft->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CombatCollisionLeft->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	CombatCollisionRight->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CombatCollisionRight->SetCollisionObjectType(ECollisionChannel::ECC_WorldDynamic);
	CombatCollisionRight->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	CombatCollisionRight->SetCollisionResponseToChannel(ECollisionChannel::ECC_Pawn, ECollisionResponse::ECR_Overlap);

	CombatCollisionLeft->OnComponentBeginOverlap.AddDynamic(this, &AMain::CombatOnOverlapBegin);
	CombatCollisionLeft->OnComponentEndOverlap.AddDynamic(this, &AMain::CombatOnOverlapEnd);

	CombatCollisionRight->OnComponentBeginOverlap.AddDynamic(this, &AMain::CombatOnOverlapBegin);
	CombatCollisionRight->OnComponentEndOverlap.AddDynamic(this, &AMain::CombatOnOverlapEnd);

	MainPlayerController = Cast<AMainPlayerController>(GetController());
}

// Called every frame
void AMain::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MovementStatus == EMovementStatus::EMS_Dead)
		return;

	float DeltaStamina = StaminaDrainRate * DeltaTime;
	float DeltaStaminaRecovery = StaminaRecoveryRate * DeltaTime;

	switch (StaminaStatus)
	{
		case EStaminaStatus::ESS_Normal:
			if (bShiftKeyDown && (bMovingForward || bMovingRight))
			{
				if (Stamina - DeltaStamina <= MinSprintStamina)
				{
					SetStaminaStatus(EStaminaStatus::ESS_BelowMinimum);
					Stamina -= DeltaStamina;
				}
				else
				{
					Stamina -= DeltaStamina;
				}
				SetMovementStatus(EMovementStatus::EMS_Sprinting);
			}
			else
			{
				if (Stamina + DeltaStaminaRecovery >= MaxStamina)
				{
					Stamina = MaxStamina;
				}
				else
				{
					Stamina += DeltaStaminaRecovery;
				}
				SetMovementStatus(EMovementStatus::EMS_Normal);
			}
			break;

		case EStaminaStatus::ESS_BelowMinimum:
			if (bShiftKeyDown && (bMovingForward || bMovingRight))
			{
				if (Stamina - DeltaStamina <= 0.f)
				{
					SetStaminaStatus(EStaminaStatus::ESS_Exhausted);
					Stamina = 0.f;
					SetMovementStatus(EMovementStatus::EMS_Normal);
				}
				else
				{
					Stamina -= DeltaStamina;
					SetMovementStatus(EMovementStatus::EMS_Sprinting);
				}
			}
			else
			{
				if (Stamina + DeltaStaminaRecovery >= MinSprintStamina)
				{
					SetStaminaStatus(EStaminaStatus::ESS_Normal);
					Stamina += DeltaStaminaRecovery;
				}
				else
				{
					Stamina += DeltaStaminaRecovery;
				}
				SetMovementStatus(EMovementStatus::EMS_Normal);
			}
			break;

		case EStaminaStatus::ESS_Exhausted:
			if (bShiftKeyDown && (bMovingForward || bMovingRight))
			{
				Stamina = 0.f;
			}
			else
			{
				SetStaminaStatus(EStaminaStatus::ESS_ExhaustedRecovering);
				Stamina += DeltaStaminaRecovery;
			}
			SetMovementStatus(EMovementStatus::EMS_Normal);
			break;

		case EStaminaStatus::ESS_ExhaustedRecovering:
			if (Stamina + DeltaStaminaRecovery >= MinSprintStamina)
			{
				SetStaminaStatus(EStaminaStatus::ESS_Normal);
				Stamina += DeltaStaminaRecovery;
			}
			else
			{
				Stamina += DeltaStaminaRecovery;
			}
			SetMovementStatus(EMovementStatus::EMS_Normal);
			break;

		default:
			;
	}

	if (bInterpToEnemy && CombatTarget)
	{
		FRotator LookAtYaw = GetLookAtRotationYaw(CombatTarget->GetActorLocation());
		FRotator InterpRotation = FMath::RInterpTo(GetActorRotation(), LookAtYaw, DeltaTime, InterpSpeed);
		
		SetActorRotation(InterpRotation);
	}

	if (CombatTarget)
	{
		CombatTargetLocation = CombatTarget->GetActorLocation();
		if (MainPlayerController)
		{
			MainPlayerController->EnemyLocation = CombatTargetLocation;
		}
	}
}

// Called to bind functionality to input
void AMain::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent); // Check is a macro that will stop the code execution here if PlayerInputComponent is invalid

	PlayerInputComponent->BindAxis("MoveForward", this, &AMain::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMain::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAxis("TurnRate", this, &AMain::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMain::LookUpAtRate);

	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Pressed, this, &AMain::Jump);
	PlayerInputComponent->BindAction("Jump", EInputEvent::IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &AMain::ShiftKeyDown);
	PlayerInputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &AMain::ShiftKeyUp);

	PlayerInputComponent->BindAction("LMB", EInputEvent::IE_Pressed, this, &AMain::LMBDown);
	PlayerInputComponent->BindAction("LMB", EInputEvent::IE_Released, this, &AMain::LMBUp);
}

void AMain::MoveForward(float Value)
{
	bMovingForward = false;
	if ((Controller != nullptr) && (Value != 0.0f) && (!bAttacking) && (MovementStatus!=EMovementStatus::EMS_Dead))
	{
		bMovingForward = true;
		const FRotator Rotation = Controller->GetControlRotation();
		// Find out which way is forward
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X); // FRotationMatrix has information regarding the X, Y and Z axes of YawRotation in space
		AddMovementInput(Direction, Value);
	}
}

void AMain::MoveRight(float Value)
{
	bMovingRight = false;
	if ((Controller != nullptr) && (Value != 0.0f) && (!bAttacking) && (MovementStatus != EMovementStatus::EMS_Dead))
	{
		bMovingRight = true;
		const FRotator Rotation = Controller->GetControlRotation();
		// Find out which way is forward
		const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y); // FRotationMatrix has information regarding the X, Y and Z axes of YawRotation in space
		AddMovementInput(Direction, Value);
	}
}

void AMain::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMain::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMain::LMBDown()
{
	bLMBDown = true;

	if (MovementStatus == EMovementStatus::EMS_Dead)
		return;

	if (ActiveOverlappingItem)
	{
		AWeapon* Weapon = Cast<AWeapon>(ActiveOverlappingItem);
		if (Weapon)
		{
			Weapon->Equip(this);
			SetActiveOverlappingItem(nullptr);
		}
	}
	else if(EquippedWeapon)
	{
		Attack();
	}
	else if (ActiveOverlappingItem == nullptr && EquippedWeapon == nullptr)
	{
		UnarmedAttack();
	}
}

void AMain::LMBUp()
{
	bLMBDown = false;
}

void AMain::DecrementHealth(float Damage)
{
	if (Health - Damage <= 0.f)
	{
		Health = 0.f;
		Die();
	}
	else
	{
		Health -= Damage;
	}
}

void AMain::Die()
{
	if (MovementStatus == EMovementStatus::EMS_Dead)
		return;
	UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

	if (AnimInstance && CombatMontage)
	{
		AnimInstance->Montage_Play(CombatMontage, 1.2f);
		AnimInstance->Montage_JumpToSection(FName("Death"));
	}
	SetMovementStatus(EMovementStatus::EMS_Dead);
}

void AMain::Jump()
{
	if (MovementStatus != EMovementStatus::EMS_Dead)
	{
		ACharacter::Jump();
	}
}

void AMain::DeathEnd()
{
	GetMesh()->bPauseAnims = true;
	GetMesh()->bNoSkeletonUpdate = true;
}

void AMain::IncrementCoins(int32 CoinCount)
{
	Coins += CoinCount;
}

void AMain::SetMovementStatus(EMovementStatus Status)
{
	MovementStatus = Status;
	if (MovementStatus == EMovementStatus::EMS_Sprinting)
	{
		GetCharacterMovement()->MaxWalkSpeed = SprintingSpeed;
	}

	else
	{
		GetCharacterMovement()->MaxWalkSpeed = RunningSpeed;
	}
}

void AMain::ShiftKeyDown()
{
	bShiftKeyDown = true;
}

void AMain::ShiftKeyUp()
{
	bShiftKeyDown = false;
}

void AMain::ShowPickupLocations()
{
	for (int32 i = 0; i < PickupLocations.Num(); i++)
	{
		UKismetSystemLibrary::DrawDebugSphere(this, PickupLocations[i], 25.f, 8, FLinearColor::Green, 10.f, 0.5f);
	}
}

void AMain::SetEquippedWeapon(AWeapon* WeaponToSet)
{
	if (EquippedWeapon)
	{
		EquippedWeapon->Destroy();
	}
	EquippedWeapon = WeaponToSet;
}

void AMain::Attack()
{
	if (!bAttacking && MovementStatus!=EMovementStatus::EMS_Dead)
	{
		bAttacking = true;
		SetInterpToEnemy(true);

		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

		if (AnimInstance && CombatMontage)
		{
			int32 Section = FMath::RandRange(0, 1);

			switch (Section)
			{
			case 0:
				AnimInstance->Montage_Play(CombatMontage, 2.2f);
				AnimInstance->Montage_JumpToSection(FName("Attack_1"), CombatMontage);
				break;

			case 1:
				AnimInstance->Montage_Play(CombatMontage, 1.8f);
				AnimInstance->Montage_JumpToSection(FName("Attack_2"), CombatMontage);
				break;

			default:
				;
			}
		}
	}
}

void AMain::UnarmedAttack()
{
	if (!bAttacking && MovementStatus != EMovementStatus::EMS_Dead)
	{
		bAttacking = true;
		SetInterpToEnemy(true);

		UAnimInstance* AnimInstance = GetMesh()->GetAnimInstance();

		if (AnimInstance && CombatMontage)
		{
			int32 Section = FMath::RandRange(0, 1);

			switch (Section)
			{
			case 0:
				AnimInstance->Montage_Play(CombatMontage, 1.8f);
				AnimInstance->Montage_JumpToSection(FName("Punch_1"), CombatMontage);
				bFirstPunchAttack = true;
				break;

			case 1:
				AnimInstance->Montage_Play(CombatMontage, 1.3f);
				AnimInstance->Montage_JumpToSection(FName("Punch_2"), CombatMontage);
				bFirstPunchAttack = false;
				break;

			default:
				;
			}
		}
	}
}

void AMain::AttackEnd()
{
	bAttacking = false;
	SetInterpToEnemy(false);

	if (bLMBDown)
	{
		Attack();
	}
}

void AMain::UnarmedAttackEnd()
{
	bAttacking = false;
	SetInterpToEnemy(false);

	if (bLMBDown && (ActiveOverlappingItem == nullptr && EquippedWeapon == nullptr))
	{
		UnarmedAttack();
	}
}

void AMain::PlaySwingSound()
{
	if (EquippedWeapon->SwingSound)
	{
		UGameplayStatics::PlaySound2D(this, EquippedWeapon->SwingSound);
	}
}

void AMain::CombatOnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor)
	{
		AEnemy* Enemy = Cast<AEnemy>(OtherActor);
		if (Enemy)
		{
			if (Enemy->HitParticles)
			{
				const USkeletalMeshSocket* TipSocket = GetMesh()->GetSocketByName("TipSocket");

				if (TipSocket)
				{
					FVector SocketLocation = TipSocket->GetSocketLocation(GetMesh());
					UGameplayStatics::SpawnEmitterAtLocation(this, Enemy->HitParticles, SocketLocation, FRotator(0.f), false);
				}
			}

			if (PunchSound)
			{
				UGameplayStatics::PlaySound2D(this, PunchSound);
			}

			if (DamageTypeClass)
			{
				UGameplayStatics::ApplyDamage(Enemy, UnarmedDamage, GetController(), this, DamageTypeClass);
			}
		}
	}
}

void AMain::CombatOnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AMain::ActivatePunchCollision()
{
	if (bFirstPunchAttack)
	{
		CombatCollisionLeft->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
	else
	{
		CombatCollisionRight->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	}
}

void AMain::DeactivatePunchCollision()
{
	if (bFirstPunchAttack)
	{
		CombatCollisionLeft->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
	else
	{
		CombatCollisionRight->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	}
}

void AMain::SetInterpToEnemy(bool Interp)
{
	bInterpToEnemy = Interp;
}

FRotator AMain::GetLookAtRotationYaw(FVector Target)
{
	FRotator LookAtRotation = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), Target);
	FRotator LookAtRotationYaw = FRotator(0.f, LookAtRotation.Yaw, 0.f);
	return LookAtRotationYaw;
}

float AMain::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser)
{
	if (Health - DamageAmount <= 0.f)
	{
		Health = 0.f;
		Die();

		if (DamageCauser)
		{
			AEnemy* Enemy = Cast<AEnemy>(DamageCauser);
			if (Enemy)
			{
				Enemy->bHasValidTarget = false;
			}
		}
	}
	else
	{
		Health -= DamageAmount;
	}

	return DamageAmount;
}

void AMain::UpdateCombatTarget()
{
	TArray<AActor*> OverlappingActors;
	GetOverlappingActors(OverlappingActors, EnemyFilter);

	if (OverlappingActors.Num() == 0)
	{
		if (MainPlayerController)
		{
			MainPlayerController->RemoveEnemyHealthBar();
		}
		return;
	}

	AEnemy* ClosestEnemy = Cast<AEnemy>(OverlappingActors[0]);
	if (ClosestEnemy)
	{
		FVector MainLocation = GetActorLocation();
		float MinDistance = (ClosestEnemy->GetActorLocation() - MainLocation).Size();

		for (auto Actor : OverlappingActors)
		{
			AEnemy* Enemy = Cast<AEnemy>(Actor);
			if (Enemy)
			{
				float DistanceToActor = (Enemy->GetActorLocation() - MainLocation).Size();
				if (DistanceToActor < MinDistance)
				{
					MinDistance = DistanceToActor;
					ClosestEnemy = Enemy;
				}
			}
		}

		if (MainPlayerController)
		{
			MainPlayerController->DisplayEnemyHealthBar();
		}
		SetCombatTarget(ClosestEnemy);
		bHasCombatTarget = true;
	}
}