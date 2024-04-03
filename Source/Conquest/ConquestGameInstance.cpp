// Fill out your copyright notice in the Description page of Project Settings.


#include "ConquestGameInstance.h"

#include "ConquestGameMode.h"
#include "ConquestGameState.h"
#include "FightGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Map/HexMap.h"
#include "Map/Tile.h"
#include "State/ConquestPlayerState.h"
#include "State/FightGameState.h"

UConquestGameInstance::UConquestGameInstance()
{
	PlayerBaseTile.PositionInMap	= FIntVector2(0,0);
	PlayerBaseTile.bEnemy			= false;
	CurrentPlayerPos				= PlayerBaseTile;
}

void UConquestGameInstance::MapTransition(const FName MapName)
{
	if (AConquestGameMode *GameModeConquest = Cast<AConquestGameMode>(GetWorld()->GetAuthGameMode()))
	{
		//Player stats
		PlayerTroops = GameModeConquest->ConquestPlayerState->TroopsAmount;
		
		//Important tiles
		TryToMoveToTile = GameModeConquest->ConquestGameState->TryToMoveToTile;
		CurrentPlayerPos = GameModeConquest->ConquestGameState->CurrentPlayerTilePos;

		//save map information
		HexMapData.SetNum(GameModeConquest->ConquestGameState->HexMap->Map.Num());
		for(int32 y = 0; y < GameModeConquest->ConquestGameState->HexMap->Map.Num(); ++y)
		{
			for (int32 x = 0;  x < GameModeConquest->ConquestGameState->HexMap->Map[y].Num(); ++x)
			{
				HexMapData[y].SetNum(GameModeConquest->ConquestGameState->HexMap->Map[y].Num());
				HexMapData[y][x].PositionInMap = GameModeConquest->ConquestGameState->HexMap->Map[y][x]->Pos;
				HexMapData[y][x].bEnemy = GameModeConquest->ConquestGameState->HexMap->Map[y][x]->bIsEnemy;
				if (!HexMapData[y][x].bEnemy)
				{
					UE_LOG(LogTemp, Error, TEXT("TILE IS FRIENDLY SAVE"));
				}
			}
		}
		
	}
	else if(AFightGameMode *GameModeFight = Cast<AFightGameMode>(GetWorld()->GetAuthGameMode()))
	{
		bWon = GameModeFight->FightGameState->bWon;
	}
	
	UGameplayStatics::OpenLevel(GetWorld(), MapName);
}
