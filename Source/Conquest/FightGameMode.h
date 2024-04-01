// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "Fighting/BaseSoldier.h"

#include "FightGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API AFightGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	class UConquestGameInstance *GameInstance;
	// UPROPERTY()
	// class AConquestGameState *FightGameState;
	// UPROPERTY()
	// class AConquestPlayerState *ConquestPlayerState;
	UPROPERTY()
	class AFightPlayerController	*Controller;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Tile")
	TSubclassOf<ABaseSoldier>	SoldierClass;
	TArray<ABaseSoldier*>		Soldiers;
};
