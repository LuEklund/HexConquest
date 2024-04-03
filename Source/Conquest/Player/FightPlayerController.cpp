// Fill out your copyright notice in the Description page of Project Settings.


#include "FightPlayerController.h"

#include "Blueprint/UserWidget.h"
#include "Conquest/ConquestGameInstance.h"

void AFightPlayerController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
	bEnableClickEvents = true;
	GameInstance = Cast<UConquestGameInstance>(GetGameInstance());
	if (GameInstance)
	{
	}
	if (FightHudClass)
	{
		FightHUD = CreateWidget(GetWorld(),FightHudClass);
		FightHUD->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nNo BP WIDGET class in AFightPlayerController\n========================================================="));
	}
}
