// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/GameModeBase.h"
#include "ConquestGameMode.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API AConquestGameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	void	MovePawnTo(class ATile *HexTile);
	void	WonBattle(bool bVictory);
	void	AITurn();
	
	UFUNCTION(BlueprintCallable, Category="Conflict")
	void	HandleConflict(bool bFight);

	void PromptTile(class ATile *HexTile);
	void clearWidget();
	void SwapPlayer(float Swap);


	UPROPERTY()
	class UConquestGameInstance *GameInstance;
	UPROPERTY()
	class AConquestGameState *ConquestGameState;
	UPROPERTY()
	class AConquestPlayerState *ConquestPlayerState;
	UPROPERTY()
	class APlayerPawnController	*Controller;
	UPROPERTY()
	class UHexMap	*HexMap;
	


protected:
	virtual void BeginPlay() override;
};
