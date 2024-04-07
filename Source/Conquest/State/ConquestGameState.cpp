// Fill out your copyright notice in the Description page of Project Settings.


#include "ConquestGameState.h"

#include "../ConquestGameInstance.h"
#include "../Map/HexMap.h"
#include "../Pawns/PawnBase.h"

// ATile	*AConquestGameState::GetTile(const FIntVector2	&Pos)
// {
// 	ATile *MyTile = HexMap->Map[Pos.Y][Pos.X];
// 	if (MyTile)
// 	{
// 		return (MyTile);
// 	}
// 	else
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("\n2=============================\nAConquestGameState: That actor does no exist\n2=================================="));
// 		return (nullptr);
// 	}
// }

// void AConquestGameState::SetupHexMap(const TArray<TArray<FTileData>> &HexMapData, FIntVector2	&WorldSize)
// {
// 	if (ClassHexMap)
// 	{
// 		HexMap = NewObject<UHexMap>(this, ClassHexMap);
// 		if (HexMap)
// 		{
// 			HexMap->InitMap(HexMapData, WorldSize);
// 		}
// 		else
// 		{
// 			UE_LOG(LogTemp, Error, TEXT("\n2=============================\nFAILED TO INIT HEX MAP\n2=================================="));
// 		}
// 	}
// 	else
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("0=============================\nFAILED TO CREATE HEXMAPn\n0=================================="));
// 	}
// }
//
// void AConquestGameState::MovePawnTo(const FVector& Vector)
// {
// 	PlayerPawn->SetActorLocation(Vector);
// }
//
//
// AActor *AConquestGameState::CreatePawn(const FVector& Vector)
// {
// 	if (!PawnBluePrintClass)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("========================================\nNo BP Tile class in AConquestGameState\n========================================================="));
// 		return (nullptr);
// 	}
// 	FVector	Loc(0.f, 0.f, 200.f);
// 	AActor *test = GetWorld()->SpawnActor<APawnBase>(PawnBluePrintClass, Loc, FRotator::ZeroRotator);
// 	if (!test)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("AConquestGameState: PawnBluePrintClass"));
// 	}
// 	PlayerPawn = Cast<APawnBase>(test);
// 	return (PlayerPawn);
// }
//
// AActor *AConquestGameState::CreateAIPawn(const FVector& Vector)
// {
// 	if (!PawnBluePrintClass)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("========================================\nNo BP Tile class in AConquestGameState\n========================================================="));
// 		return (nullptr);
// 	}
// 	FVector	Loc(0.f, 0.f, 200.f);
// 	AActor *test = GetWorld()->SpawnActor<APawnBase>(PawnBluePrintClass, Loc, FRotator::ZeroRotator);
// 	if (!test)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("AConquestGameState: PawnBluePrintClass"));
// 	}
// 	AIPawn = Cast<APawnBase>(test);
// 	AIPawn->SetActorLocation(Vector);
// 	return (PlayerPawn);
// }
//
//
