// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "FightPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API AFightPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

public:
	UPROPERTY()
	class UConquestGameInstance *GameInstance;

	UPROPERTY(EditAnywhere, Category="Widget")
	TSubclassOf<UUserWidget>	FightHudClass;
	
	UPROPERTY()
	UUserWidget	*FightHUD;
};
