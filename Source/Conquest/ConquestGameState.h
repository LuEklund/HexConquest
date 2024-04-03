// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "ConquestGameInstance.h"
#include "Map/Tile.h"
#include "ConquestGameState.generated.h"


/**
 * 
 */
UCLASS()
class CONQUEST_API AConquestGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	void		SetupHexMap(const TArray<TArray<struct FTileData>> &HexMapData);
	AActor		*CreatePawn(const FVector& Vector);
	void		MovePawnTo(const FVector& Vector);
	ATile*		GetTile(const FIntVector2& Pos);

	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Map")
	TSubclassOf<class UHexMap>	ClassHexMap;
	UPROPERTY()
	class UHexMap	*HexMap;


	UPROPERTY(EditAnywhere, Category="Pawn")
	TSubclassOf<class APawnBase>	PawnBluePrintClass;
	UPROPERTY()
	class APawnBase	*PlayerPawn;

	UPROPERTY()
	FTileData	TryToMoveToTile;

	UPROPERTY()
	FTileData	CurrentPlayerTilePos;
};
