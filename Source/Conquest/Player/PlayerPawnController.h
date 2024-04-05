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
	virtual void BeginPlay() override;
	void PromptToFight();
	void TogglePlayerTurn(bool bCanPlay);


	UPROPERTY(EditAnywhere, Category="Widget")
	TSubclassOf<UUserWidget>	WidgetClass;

	UPROPERTY(EditAnywhere, Category="Widget")
	TSubclassOf<UUserWidget>	WidgetHUDClass;
	
	UPROPERTY()
	UUserWidget	*PromptWidget;

	UPROPERTY()
	UUserWidget	*HUDWidget;

};
