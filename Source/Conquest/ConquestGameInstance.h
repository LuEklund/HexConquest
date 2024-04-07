// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Map/Tile.h"
#include "ConquestGameInstance.generated.h"

/**
 * 
 */


UCLASS()
class CONQUEST_API UConquestGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UConquestGameInstance();

	class UHexMap	*GetHexMap();



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Map")
	TSubclassOf<class UHexMap>	HexMapBlueprint;
	UPROPERTY()
	class UHexMap	*HexMap;

	int32	PlayerAmount = 3;
	
	// FTileData					TryToMoveToTile;
	// FTileData					CurrentPlayerPos;
	// FTileData					PlayerBaseTile;
	// FTileData					AIBaseTile;
	// FTileData					CurrentAITile;
	// bool						bWon = false;

	int8	PlayerTroops = 0;
	int32	PlayerGold = 0;

	void LoadHexMap();
	void SaveHexMap();
	void	MapTransition(const FName MapName);
};
