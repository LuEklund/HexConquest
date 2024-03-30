// Fill out your copyright notice in the Description page of Project Settings.


#include "ConquestGameState.h"

#include "Map/HexMap.h"

AConquestGameState::AConquestGameState()
{
}

void AConquestGameState::BeginPlay()
{
	Super::BeginPlay();
	if (ClassHexMap)
	{
		HexMap = NewObject<UHexMap>(this, ClassHexMap);
		if (HexMap)
		{
			HexMap->InitMap();
		}
		else
		{
			UE_LOG(LogTemp, Display, TEXT("\n2=============================\nFAILED TO INIT HEX MAP\n2=================================="));
		}
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("0=============================\nFAILED TO CREATE HEXMAPn\n0=================================="));
	}


}
