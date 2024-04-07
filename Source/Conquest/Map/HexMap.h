// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Tile.h"
#include "HexMap.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class CONQUEST_API UHexMap : public UObject
{
	GENERATED_BODY()
public:
	void		InitMap(int32 Y, int32 X);
	void		SummonPawns(int32 Amount);
	virtual void BeginDestroy() override;
	// void		MovePawnTo(const FVector& Vector);
	// ATile*		GetTile(const FIntVector2& Pos);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tile")
	TSubclassOf<ATile>	TileBluePrintClass;

	UPROPERTY(EditAnywhere, Category="Pawn")
	TSubclassOf<class APawnBase>	PawnBluePrint;

	// UPROPERTY()
	TArray<TStrongObjectPtr<class APawnBase>>		PlayerPawns;

	TArray<TArray<class ATile *>>	Map;
};
