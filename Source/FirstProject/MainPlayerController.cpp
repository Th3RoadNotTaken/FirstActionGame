// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Framework/Application/SlateApplication.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (HUDOverlayAsset)
	{
		HudOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
	}

	HudOverlay->AddToViewport(0);

	// Visibility of the HUD
	HudOverlay->SetVisibility(ESlateVisibility::Hidden);

	if (WEnemyHealthBar)
	{
		EnemyHealthBar = CreateWidget<UUserWidget>(this, WEnemyHealthBar);

		if (EnemyHealthBar)
		{
			EnemyHealthBar->AddToViewport(0);
			EnemyHealthBar->SetVisibility(ESlateVisibility::Hidden);
		}
		FVector2D Alignment(0.f, 0.f);
		EnemyHealthBar->SetAlignmentInViewport(Alignment);
	}

	if (WPauseMenu)
	{
		PauseMenu = CreateWidget<UUserWidget>(this, WPauseMenu);

		if (PauseMenu)
		{
			PauseMenu->AddToViewport(10);
			PauseMenu->SetVisibility(ESlateVisibility::Hidden);
		}
	}

	if (WShieldHealthBar)
	{
		ShieldHealthBar = CreateWidget<UUserWidget>(this, WShieldHealthBar);

		if (ShieldHealthBar)
		{
			ShieldHealthBar->AddToViewport(0);
			ShieldHealthBar->SetVisibility(ESlateVisibility::Hidden);
		}
		FVector2D Alignment(0.f, 0.f);
		ShieldHealthBar->SetAlignmentInViewport(Alignment);
	}

	if (WIntroductionMenu)
	{
		IntroductionMenu = CreateWidget<UUserWidget>(this, WIntroductionMenu);

		if (IntroductionMenu)
		{
			IntroductionMenu->AddToViewport(5);
			IntroductionMenu->SetVisibility(ESlateVisibility::Hidden);
		}
	}
}

void AMainPlayerController::DisplayHUDOverlay()
{
	HudOverlay->SetVisibility(ESlateVisibility::Visible);
}

void AMainPlayerController::DisplayEnemyHealthBar()
{
	if (EnemyHealthBar)
	{
		bEnemyHealthBarVisible = true;
		EnemyHealthBar->SetVisibility(ESlateVisibility::Visible);
	}
}

void AMainPlayerController::RemoveEnemyHealthBar()
{
	if (EnemyHealthBar)
	{
		bEnemyHealthBarVisible = false;
		EnemyHealthBar->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AMainPlayerController::DisplayShieldHealthBar()
{
	if (ShieldHealthBar)
	{
		bShieldHealthBarVisible = true;
		ShieldHealthBar->SetVisibility(ESlateVisibility::Visible);
	}
}

void AMainPlayerController::RemoveShieldHealthBar()
{
	if (ShieldHealthBar)
	{
		bShieldHealthBarVisible = false;
		ShieldHealthBar->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AMainPlayerController::DisplayPauseMenu_Implementation()
{
	if (PauseMenu)
	{
		bPauseMenuVisible = true;
		PauseMenu->SetVisibility(ESlateVisibility::Visible);

		FInputModeGameAndUI InputModeGameAndUI;
		//InputModeGameAndUI.SetWidgetToFocus(PauseMenu->TakeWidget());
		SetInputMode(InputModeGameAndUI); // Allows the Game and UI to respond to player input
		bShowMouseCursor = true;
		UGameplayStatics::SetGamePaused(GetWorld(), true);
	}
}

void AMainPlayerController::RemovePauseMenu_Implementation()
{
	if (PauseMenu)
	{
		//PauseMenu->SetVisibility(ESlateVisibility::Hidden);		// Implemented in the BP after a certain delay so that the exit animation will play first
		GameModeOnly();
		bShowMouseCursor = false;
		bPauseMenuVisible = false;
		UGameplayStatics::SetGamePaused(GetWorld(), false);
	}
}

void AMainPlayerController::DisplayIntroductionMenu_Implementation()
{
	if (IntroductionMenu)
	{
		bIntroductionMenuVisible = true;
		IntroductionMenu->SetVisibility(ESlateVisibility::Visible);
	}
}

void AMainPlayerController::RemoveFirstIntroductionBox_Implementation()
{

}

void AMainPlayerController::RemoveSecondIntroductionBox_Implementation()
{

}

void AMainPlayerController::RemoveThirdIntroductionBox_Implementation()
{

}

void AMainPlayerController::TogglePauseMenu()
{
	if (bPauseMenuVisible)
	{
		RemovePauseMenu();
	}
	else
		DisplayPauseMenu();
}

void AMainPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (EnemyHealthBar)
	{
		FVector2D PositionInViewport;
		ProjectWorldLocationToScreen(EnemyLocation, PositionInViewport);
		PositionInViewport.Y -= 85.f; // In the 2D screen, the origin is located at the top left

		FVector2D SizeInViewport = FVector2D(300.f, 25.f);

		EnemyHealthBar->SetPositionInViewport(PositionInViewport);
		EnemyHealthBar->SetDesiredSizeInViewport(SizeInViewport);
	}
}

void AMainPlayerController::GameModeOnly()
{
	FInputModeGameOnly InputModeGameOnly;
	SetInputMode(InputModeGameOnly);
}