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
	void PromptTile();
	void TogglePlayerTurn(bool bCanPlay);
	void PossesPawn(class APawnBase *PawnToPosses);


	UPROPERTY(EditAnywhere, Category="Widget")
	TSubclassOf<UUserWidget>	WidgetClass;

	UPROPERTY(EditAnywhere, Category="Widget")
	TSubclassOf<UUserWidget>	WidgetHUDClass;
	
	UPROPERTY()
	UUserWidget	*PromptWidget;

	UPROPERTY()
	UUserWidget	*HUDWidget;



	//============[Enhanced Input]======================================

	void	EnhancedInputZoom(const struct FInputActionValue& value);
	void	EnhancedInputMove(const struct FInputActionValue& value);
	void	EnhancedInputPlayerSwap(const struct FInputActionValue& value);
	
	//The mapping context
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enhanced Input")
	class UInputMappingContext *InputMappingContext;

	//Zoom
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enhanced Input")
	class UInputAction *InputZoom;

	//Movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enhanced Input")
	class UInputAction *InputMove;

	//Player swap
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enhanced Input")
	class UInputAction *InputPlayerSwap;

	//===================================================================

};
