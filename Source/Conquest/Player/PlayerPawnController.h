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
	void MovePawnTo(const FVector& Vector);
	void CreatePawn(const FVector& Vector);


	UPROPERTY(EditAnywhere, Category="Pawn")
	TSubclassOf<class APawnBase>	PawnBluePrintClass;

	class APawnBase	*Pawn;

};
