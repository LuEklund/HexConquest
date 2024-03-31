// Fill out your copyright notice in the Description page of Project Settings.


#include "FightPlayerController.h"

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
}
