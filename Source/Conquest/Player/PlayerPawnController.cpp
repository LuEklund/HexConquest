// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnController.h"
#include "Blueprint/UserWidget.h"


void APlayerPawnController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
	bEnableClickEvents = true;

	if (WidgetHUDClass)
	{
		HUDWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetHUDClass);
		HUDWidget->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nNo BP WIDGET class in APlayerPawnController\n========================================================="));
	}

}



void APlayerPawnController::PromptToFight()
{
	if (!WidgetClass)
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nNo BP WIDGET class in APlayerPawnController\n========================================================="));
		return ;
	}
	if (!PromptWidget)
	{
		PromptWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
	}
	if(PromptWidget->IsInViewport())
	{
		PromptWidget->RemoveFromParent();
	}
	PromptWidget->AddToViewport();
}

