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
	UHexMap();
	void	InitMap();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tile")
	TSubclassOf<ATile>	TileBluePrintClass;
	
	TArray<TArray<class ATile *>> Map;
};
