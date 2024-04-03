// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FightGameState.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API AFightGameState : public AGameStateBase
{
	GENERATED_BODY()
public:
	int32	EnemyTroops = 8;
	bool	bWon = false;
};
