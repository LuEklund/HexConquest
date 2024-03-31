// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ConquestGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CONQUEST_API UConquestGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	// TArray<TArray<class >>
	FVector	TempHexCords;
	bool	bWon = false;

	int8	PlayerTroops = 0;

	void	MapTransition(const FName MapName);
};
