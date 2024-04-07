// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGameConquest.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API USaveGameConquest : public USaveGame
{
	GENERATED_BODY()

public:
	TArray<class APawnBase *>		PlayerPawns;
	TArray<TArray<class ATile *>>	Map;
	// void LoadHexMap();
	// void SaveHexMap();
	
};
