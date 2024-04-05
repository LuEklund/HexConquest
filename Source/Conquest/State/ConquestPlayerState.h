// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ConquestPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API AConquestPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Troops")
	int32		TroopsAmount = 8;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Troops")
	int32		Gold = 200;
};
