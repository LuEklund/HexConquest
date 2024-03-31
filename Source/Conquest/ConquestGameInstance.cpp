// Fill out your copyright notice in the Description page of Project Settings.


#include "ConquestGameInstance.h"

#include "Kismet/GameplayStatics.h"
#include "Player/PlayerPawnController.h"
#include "Player/FightPlayerController.h"

void UConquestGameInstance::MapTransition(const FName MapName)
{
	if (APlayerPawnController *PlayerPawnController = Cast<APlayerPawnController>(GetFirstLocalPlayerController(GetWorld())))
	{
		TempHexCords = PlayerPawnController->TempTileCord;
		PlayerTroops = PlayerPawnController->TroopsAmount;
	}
	else if (AFightPlayerController *FightPlayerController = Cast<AFightPlayerController>(GetFirstLocalPlayerController(GetWorld())))
	{
		bWon = FightPlayerController->bWon;
	}
	UGameplayStatics::OpenLevel(GetWorld(), MapName);
}
