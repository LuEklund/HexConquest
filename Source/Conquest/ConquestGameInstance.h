// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
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
	bool		bEnemy;
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
	bool						bWon = false;

	int8	PlayerTroops = 0;

	void	MapTransition(const FName MapName);
};
