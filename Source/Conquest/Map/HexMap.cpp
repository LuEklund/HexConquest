// Fill out your copyright notice in the Description page of Project Settings.


#include "HexMap.h"
#include "Tile.h"
#include "../ConquestGameInstance.h"

void UHexMap::InitMap(const TArray<TArray<FTileData>> &HexMapData, FIntVector2	&WorldSize)
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
	Map.SetNum(WorldSize.Y);
	for (int32 y = 0; y < Map.Num(); ++y)
	{
		Map[y].SetNum(WorldSize.X);
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
			if(HexMapData.Num())
			{
				if(HexMapData[y][x].TileOwner == ETileOwner::Player)
				{
					TileActor->Conqured(true);
				}
			}
			else
			{
				if (FMath::RandRange(0,1))
				{
					TileActor->TileOwner = ETileOwner::Water;
					TileActor->ChangeMaterial(3);
				}
			}
			TileActor->Pos.Y = y;
			TileActor->Pos.X = x;
			Map[y][x] = TileActor;
		}
	}
}
