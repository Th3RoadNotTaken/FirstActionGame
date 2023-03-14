// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class FIRSTPROJECT_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	/** Reference to the UMG asset in the editor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> HUDOverlayAsset;
	
	/** Variable to hold the widget after creating it */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	UUserWidget* HudOverlay;

	/** Reference to the enemy health bar asset in the editor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> WEnemyHealthBar;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets")
	UUserWidget* EnemyHealthBar;

	bool bEnemyHealthBarVisible;

	void DisplayEnemyHealthBar();
	void RemoveEnemyHealthBar();

	FVector EnemyLocation;

	/** Reference to the shield health bar asset in the editor */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> WShieldHealthBar;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets")
	UUserWidget* ShieldHealthBar;

	bool bShieldHealthBarVisible;

	void DisplayShieldHealthBar();
	void RemoveShieldHealthBar();
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets")
	bool bHasShield;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> WPauseMenu;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets")
	UUserWidget* PauseMenu;

	bool bPauseMenuVisible;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Widgets")
	void DisplayPauseMenu();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Widgets")
	void RemovePauseMenu();
	void TogglePauseMenu();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<UUserWidget> WIntroductionMenu;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets")
	UUserWidget* IntroductionMenu;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Widgets")
	bool bIntroductionMenuVisible;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets")
	bool MoveDone;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets")
	bool RotateDone;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Widgets")
	bool AttackDone;

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Widgets")
	void DisplayIntroductionMenu();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Widgets")
	void RemoveFirstIntroductionBox();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Widgets")
	void RemoveSecondIntroductionBox();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Widgets")
	void RemoveThirdIntroductionBox();

	void GameModeOnly();

	UFUNCTION(BlueprintCallable)
	void DisplayHUDOverlay();

protected:

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
};
