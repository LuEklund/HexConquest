// Fill out your copyright notice in the Description page of Project Settings.


#include "ConquestGameState.h"

#include "Map/HexMap.h"
#include "Player/PlayerPawnController.h"

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
			AActor *myActor = Cast<AActor>(HexMap->Map[0][0]);
			if (myActor)
			{
				FVector Location = myActor->GetActorLocation();
				APlayerPawnController * PlayerPawnController = Cast<APlayerPawnController>(GetWorld()->GetFirstPlayerController());
				if (PlayerPawnController)
				{
					PlayerPawnController->CreatePawn(Location);
				}
				else
				{
					UE_LOG(LogTemp, Error, TEXT("\n2=============================\nERROR in PlayerPawnControler in GameState\n2=================================="));
				}
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("\n2=============================\nSOmething wrong with saving pointer in map\n2=================================="));
			}
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("\n2=============================\nFAILED TO INIT HEX MAP\n2=================================="));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("0=============================\nFAILED TO CREATE HEXMAPn\n0=================================="));
	}


}
