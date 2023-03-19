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

	if (WItemCost)
	{
		ItemCost = CreateWidget<UUserWidget>(this, WItemCost);

		if (ItemCost)
		{
			ItemCost->AddToViewport(0);
			ItemCost->SetVisibility(ESlateVisibility::Hidden);
		}
		FVector2D Alignment(0.f, 0.f);
		ItemCost->SetAlignmentInViewport(Alignment);
	}

	if (WInsufficientCoins)
	{
		InsufficientCoins = CreateWidget<UUserWidget>(this, WInsufficientCoins);

		if (InsufficientCoins)
		{
			InsufficientCoins->AddToViewport(0);
			InsufficientCoins->SetVisibility(ESlateVisibility::Hidden);
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

void AMainPlayerController::DisplayItemCost()
{
	if (ItemCost)
	{
		ItemCost->SetVisibility(ESlateVisibility::Visible);
	}
}

void AMainPlayerController::RemoveItemCost()
{
	if (ItemCost)
	{
		ItemCost->SetVisibility(ESlateVisibility::Hidden);
	}
}

void AMainPlayerController::DisplayInsufficientCoins()
{
	if (InsufficientCoins)
	{
		InsufficientCoins->SetVisibility(ESlateVisibility::Visible);
	}
}

void AMainPlayerController::RemoveInsufficientCoins()
{
	if (InsufficientCoins)
	{
		InsufficientCoins->SetVisibility(ESlateVisibility::Hidden);
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

void AMainPlayerController::RemoveFourthIntroductionBox_Implementation()
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
		PositionInViewport.Y -= 90.f; // In the 2D screen, the origin is located at the top left

		FVector2D SizeInViewport = FVector2D(300.f, 25.f);

		EnemyHealthBar->SetPositionInViewport(PositionInViewport);
		EnemyHealthBar->SetDesiredSizeInViewport(SizeInViewport);
	}

	if (ItemCost)
	{
		FVector2D PositionInViewport;
		ProjectWorldLocationToScreen(ItemLocation, PositionInViewport);
		PositionInViewport.Y -= 15.f; // In the 2D screen, the origin is located at the top left

		FVector2D SizeInViewport = FVector2D(300.f, 100.f);

		ItemCost->SetPositionInViewport(PositionInViewport);
		ItemCost->SetDesiredSizeInViewport(SizeInViewport);
	}
}

void AMainPlayerController::GameModeOnly()
{
	FInputModeGameOnly InputModeGameOnly;
	SetInputMode(InputModeGameOnly);
}