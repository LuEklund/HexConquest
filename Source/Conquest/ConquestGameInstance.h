// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Map/Tile.h"
#include "ConquestGameInstance.generated.h"

/**
 * 
 */


USTRUCT(Blueprintable)
struct FTileData
{
	GENERATED_BODY()

	UPROPERTY()
	FIntVector2	PositionInMap;
	
	UPROPERTY()
	TEnumAsByte<ETileOwner> TileOwner;
};

UCLASS()
class CONQUEST_API UConquestGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UConquestGameInstance();
	
	TArray<TArray<FTileData>>	HexMapData;
	FTileData					TryToMoveToTile;
	FTileData					CurrentPlayerPos;
	FTileData					PlayerBaseTile;
	FTileData					AIBaseTile;
	FTileData					CurrentAITile;
	bool						bWon = false;

	int8	PlayerTroops = 0;
	int32	PlayerGold = 0;

	FIntVector2					WorldSize;

	void	MapTransition(const FName MapName);
};
