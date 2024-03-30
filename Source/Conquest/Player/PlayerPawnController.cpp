// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnController.h"
#include "../Pawns/PawnBase.h"

void APlayerPawnController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
	bEnableClickEvents = true;

	
	// ATile* TileActor = Cast<ATile>(GetWorld()->SpawnActor<ATile>(TileBluePrintClass, Loc, FRotator::ZeroRotator));

}

void APlayerPawnController::MovePawnTo(const FVector& Vector)
{
	Pawn->SetActorLocation(Vector);
}

void APlayerPawnController::CreatePawn(const FVector& Vector)
{
	if (!PawnBluePrintClass)
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nNo BP Tile class in PlayerPawnController\n========================================================="));
		return ;
	}
	FVector	Loc(0.f, 0.f, 200.f);
	AActor *test = GetWorld()->SpawnActor<APawnBase>(PawnBluePrintClass, Loc, FRotator::ZeroRotator);
	if (!test)
	{
		UE_LOG(LogTemp, Display, TEXT("SAAAAAAAAAAAAAAAAAAAAD111"));
	}
	Pawn = Cast<APawnBase>(test);
	if (!Pawn)
	{
		UE_LOG(LogTemp, Display, TEXT("SAAAAAAAAAAAAAAAAAAAAD222"));
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("HAPYYYYYYYYYYYYYYYYYYYYYYYYYY"));

	}
	MovePawnTo(Vector);
}
