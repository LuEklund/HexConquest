// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerPawnController.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API APlayerPawnController : public APlayerController
{
	GENERATED_BODY()

public:

	FVector	TempTileCord;
	UPROPERTY(EditAnywhere, Category="Troops")
	int8		TroopsAmount = 8;

	virtual void BeginPlay() override;
	void MovePawnTo(const FVector& Vector);
	void CreatePawn(const FVector& Vector);
	void PromptToFight(const FVector& Vector);
	void	WonBattle(bool bVictory);
	
	UFUNCTION(BlueprintCallable, Category="Conflict")
	void	HandleConflict(bool bFight);

	UPROPERTY(EditAnywhere, Category="Pawn")
	TSubclassOf<class APawnBase>	PawnBluePrintClass;

	UPROPERTY()
	class APawnBase	*HexPawn;

	UPROPERTY()
	class UConquestGameInstance *GameInstance;

	UPROPERTY(EditAnywhere, Category="Widget")
	TSubclassOf<UUserWidget>	WidgetClass;
	
	UPROPERTY()
	UUserWidget	*PromptWidget;

};
