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
		UE_LOG(LogTemp, Error, TEXT("No BP Tile class in HexMap2"));
		return ;
	}
	//Get a Tiles width to use as sapwn location
	ATile* TmpTile = Cast<ATile>(GetWorld()->SpawnActor<ATile>(TileBluePrintClass, FVector(0.f,0.f, 1000.f), FRotator::ZeroRotator));
	FVector Min, Max;
	TmpTile->Tile->GetLocalBounds(Min, Max);
	float	TileWidth = Max.X - Min.X;

	//Start creating tiles
	Map.SetNum(10);
	for (int32 y = 0; y < Map.Num(); ++y)
	{
		Map[y].SetNum(5);
		for (int32 x = 0; x < Map[y].Num(); ++x)
		{
			FVector	Loc(0.f,0.f,5.f);
			if (y % 2 == 0)
			{
				Loc.X = x * TileWidth + TileWidth / 2.f;
				Loc.Y = y * 0.82f * TileWidth;
			}
			else
			{
				Loc.X = x * TileWidth;
				Loc.Y = y * 0.82f * TileWidth;
			}
			ATile* TileActor = Cast<ATile>(GetWorld()->SpawnActor<ATile>(TileBluePrintClass, Loc, FRotator::ZeroRotator));
			// FVector Min, Max;
			// TileActor->Tile->GetLocalBounds(Min, Max);
			// UE_LOG(LogTemp, Display, TEXT("created: Y: %d, X: %d, WIDTH? %f"), y, x, Max.X - Min.X);
			Map[y][x] = TileActor;
		}
	}
}
