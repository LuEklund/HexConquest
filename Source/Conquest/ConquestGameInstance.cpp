// Fill out your copyright notice in the Description page of Project Settings.


#include "ConquestGameInstance.h"

#include "ConquestGameMode.h"
#include "ConquestGameState.h"
#include "Kismet/GameplayStatics.h"
#include "Map/HexMap.h"
#include "Map/Tile.h"
#include "Pawns/PawnBase.h"
#include "Player/FightPlayerController.h"
#include "State/ConquestPlayerState.h"

void UConquestGameInstance::MapTransition(const FName MapName)
{
	if (AConquestGameMode *GameMode = Cast<AConquestGameMode>(GetWorld()->GetAuthGameMode()))
	{
		//Player stats
		PlayerTroops = GameMode->ConquestPlayerState->TroopsAmount;
		
		//Important tiles
		TryToMoveToTile = GameMode->ConquestGameState->TryToMoveToTile;
		CurrentPlayerPos = GameMode->ConquestGameState->CurrentPlayerTilePos;

		//save map information
		HexMapData.SetNum(GameMode->ConquestGameState->HexMap->Map.Num());
		for(int32 y = 0; y < GameMode->ConquestGameState->HexMap->Map.Num(); ++y)
		{
			for (int32 x = 0;  x < GameMode->ConquestGameState->HexMap->Map[y].Num(); ++x)
			{
				HexMapData[y].SetNum(GameMode->ConquestGameState->HexMap->Map[y].Num());
				HexMapData[y][x].PositionInMap = GameMode->ConquestGameState->HexMap->Map[y][x]->Pos;
				HexMapData[y][x].bEnemy = GameMode->ConquestGameState->HexMap->Map[y][x]->bIsEnemy;
				if (!HexMapData[y][x].bEnemy)
				{
					UE_LOG(LogTemp, Error, TEXT("TILE IS FRIENDLY SAVE"));
				}
			}
		}
		
	}
	else if (AFightPlayerController *FightPlayerController = Cast<AFightPlayerController>(GetFirstLocalPlayerController(GetWorld())))
	{
		bWon = FightPlayerController->bWon;
	}
	UGameplayStatics::OpenLevel(GetWorld(), MapName);
	// if (APlayerPawnController *PlayerPawnController = Cast<APlayerPawnController>(GetFirstLocalPlayerController(GetWorld())))
	// {
	// 	// TempHexCords = PlayerPawnController->TempTileCord;
	// 	// PlayerTroops = PlayerPawnController->TroopsAmount;
	// }
}
