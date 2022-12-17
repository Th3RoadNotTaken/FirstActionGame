// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"
#include "Blueprint/UserWidget.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (HUDOverlayAsset)
	{
		HudOverlay = CreateWidget<UUserWidget>(this, HUDOverlayAsset);
	}

	HudOverlay->AddToViewport();

	// Visibility of the HUD
	HudOverlay->SetVisibility(ESlateVisibility::Visible);
}