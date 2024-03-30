// Fill out your copyright notice in the Description page of Project Settings.


#include "HexMap.h"
#include "Tile.h"

UHexMap::UHexMap()
{
	// Map.SetNum(10);
	// for (int32 y = 0; y < Map.Num(); ++y)
	// {
	// 	Map[y].SetNum(10);
	// 	for (int32 x = 0; x < Map[y].Num(); ++x)
	// 	{
	// 		UE_LOG(LogTemp, Display, TEXT("created: Y: %d, X: %d"), y, x);
	// 		AActor* TileActor = GetWorld()->SpawnActor<ATile>(ATile::StaticClass());
	// 		//Map[y][x] = Cast<ATile>(TileActor);
	// 	}
	// }
}

void UHexMap::InitMap()
{
	if (!TileBluePrintClass)
	{
		UE_LOG(LogTemp, Display, TEXT("No BP Tile class in HexMap"));
		return ;
	}
	Map.SetNum(10);
	for (int32 y = 0; y < Map.Num(); ++y)
	{
		Map[y].SetNum(10);
		for (int32 x = 0; x < Map[y].Num(); ++x)
		{
			// FVector(x * );
			ATile* TileActor = Cast<ATile>(GetWorld()->SpawnActor<ATile>(TileBluePrintClass));
			UE_LOG(LogTemp, Display, TEXT("created: Y: %d, X: %d, "), y, x);
			Map[y][x] = TileActor;
		}
	}
}
