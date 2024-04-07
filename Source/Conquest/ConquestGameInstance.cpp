// Fill out your copyright notice in the Description page of Project Settings.


#include "ConquestGameInstance.h"

#include "SaveGameConquest.h"
#include "GameModes/ConquestGameMode.h"
#include "State/ConquestGameState.h"
#include "GameModes/FightGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Map/HexMap.h"
#include "Map/Tile.h"
#include "State/ConquestPlayerState.h"
#include "State/FightGameState.h"

UConquestGameInstance::UConquestGameInstance()
{
	UE_LOG(LogTemp, Error, TEXT("\n2=============================\nCREATED\n2=================================="));

	// PlayerBaseTile.PositionInMap	= FIntVector2(0,0);
	// PlayerBaseTile.TileOwner		= ETileOwner::Player;
	// CurrentPlayerPos				= PlayerBaseTile;
	// WorldSize						= FIntVector2(10,10);
	// AIBaseTile.PositionInMap		= FIntVector2(FMath::RandRange(2,WorldSize.X - 1), FMath::RandRange(2,WorldSize.Y - 1));
	// AIBaseTile.TileOwner			= ETileOwner::Enemy;
	// CurrentAITile					= AIBaseTile;
	
}

UHexMap* UConquestGameInstance::GetHexMap()
{
	if (!HexMap)
	{
		if (HexMapBlueprint)
		{
			HexMap = NewObject<UHexMap>(this, HexMapBlueprint);
			if (HexMap)
			{
				//Setup The map
				HexMap->InitMap(10, 10);
				//Summon the players
				HexMap->SummonPawns(PlayerAmount);
				UE_LOG(LogTemp, Warning, TEXT("\n2=============================\nUConquestGameInstance::GetHexMap : Created new\n2=================================="));
				return (HexMap);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("\n2=============================\nFAILED TO INIT HEX MAP\n2=================================="));
				return nullptr;
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("0=============================\nFAILED TO CREATE HEXMAPn\n0=================================="));
			return nullptr;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("\n2=============================\nUConquestGameInstance::GetHexMap : Already exist\n2=================================="));
		LoadHexMap();
		return (HexMap);
	}
}

void UConquestGameInstance::MapTransition(const FName MapName)
{
	USaveGameConquest *SaveGameConquest = NewObject<USaveGameConquest>();
	if (AConquestGameMode *GameModeConquest = Cast<AConquestGameMode>(GetWorld()->GetAuthGameMode()))
	{
		//Player stats
		PlayerTroops = GameModeConquest->ConquestPlayerState->TroopsAmount;
		PlayerGold = GameModeConquest->ConquestPlayerState->Gold;
		SaveHexMap();
		//Important tiles
		// TryToMoveToTile = GameModeConquest->ConquestGameState->TryToMoveToTile;
		// CurrentPlayerPos = GameModeConquest->ConquestGameState->CurrentPlayerTilePos;

		//save map information
		// HexMapData.SetNum(GameModeConquest->ConquestGameState->HexMap->Map.Num());
		// for(int32 y = 0; y < GameModeConquest->ConquestGameState->HexMap->Map.Num(); ++y)
		// {
		// 	for (int32 x = 0;  x < GameModeConquest->ConquestGameState->HexMap->Map[y].Num(); ++x)
		// 	{
		// 		HexMapData[y].SetNum(GameModeConquest->ConquestGameState->HexMap->Map[y].Num());
		// 		HexMapData[y][x].PositionInMap = GameModeConquest->ConquestGameState->HexMap->Map[y][x]->Pos;
		// 		HexMapData[y][x].TileOwner = GameModeConquest->ConquestGameState->HexMap->Map[y][x]->TileOwner;
		// 	}
		// }
		
	}
	else if(AFightGameMode *GameModeFight = Cast<AFightGameMode>(GetWorld()->GetAuthGameMode()))
	{
		// bWon = GameModeFight->FightGameState->bWon;
	}
	
	UGameplayStatics::OpenLevel(GetWorld(), MapName);
}



void UConquestGameInstance::LoadHexMap()
{
	// UConquestGameInstance *GameInstance = Cast<UConquestGameInstance>(UGameplayStatics::GetGameInstance(this));
	USaveGameConquest* LoadedGame = Cast<USaveGameConquest>(UGameplayStatics::LoadGameFromSlot("Default", 0));
	// if (!GameInstance)
	// {
	// 	UE_LOG(LogTemp, Error, TEXT("0=============================\n USaveGameConquest::LoadHexMap : No GameInstance\n0=================================="));
	// 	return ;
	// }
	if (!LoadedGame)
	{
		UE_LOG(LogTemp, Error, TEXT("0=============================\n USaveGameConquest::LoadHexMap : No LoadedGame\n0=================================="));
		return ;
	}
	UE_LOG(LogTemp, Error, TEXT("0=============================\n USaveGameConquest::SaveHexMap : LOADED! %d\n0=================================="), LoadedGame->Map.Num());

	HexMap->PlayerPawns = LoadedGame->PlayerPawns;
	HexMap->Map = LoadedGame->Map;
}

void UConquestGameInstance::SaveHexMap()
{
	// UConquestGameInstance *GameInstance = Cast<UConquestGameInstance>(UGameplayStatics::GetGameInstance(this));
	USaveGameConquest* SaveGameInstance = Cast<USaveGameConquest>(UGameplayStatics::CreateSaveGameObject(USaveGameConquest::StaticClass()));
	// if (!GameInstance)
	// {
	// 	UE_LOG(LogTemp, Error, TEXT("0=============================\n USaveGameConquest::SaveHexMap : No GameInstance\n0=================================="));
	// 	return ;
	// }
	if (!SaveGameInstance)
	{
		UE_LOG(LogTemp, Error, TEXT("0=============================\n USaveGameConquest::SaveHexMap : No SaveGameInstance\n0=================================="));
		return ;
	}
	SaveGameInstance->PlayerPawns = HexMap->PlayerPawns;
	SaveGameInstance->Map = HexMap->Map;
	UE_LOG(LogTemp, Error, TEXT("0=============================\n USaveGameConquest::SaveHexMap : SAVED! Game: %d, save: %d\n0=================================="),HexMap->Map.Num(),  SaveGameInstance->Map.Num());
	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Default"), 0);	
}
