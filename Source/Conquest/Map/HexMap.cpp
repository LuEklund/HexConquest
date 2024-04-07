// Fill out your copyright notice in the Description page of Project Settings.


#include "HexMap.h"
#include "Tile.h"
#include "Conquest/Pawns/PawnBase.h"

void UHexMap::InitMap(int32 Y, int32 X)
{

	if (!TileBluePrintClass)
	{
		UE_LOG(LogTemp, Error, TEXT("No BP Tile class in HexMap2"));
		return ;
	}

	// Get a Tiles width to use as sapwn location
	 ATile* TmpTile = Cast<ATile>(GetWorld()->SpawnActor<ATile>(TileBluePrintClass, FVector(0.f,0.f, 1000.f), FRotator::ZeroRotator));
	 FVector Min, Max;
	 TmpTile->Tile->GetLocalBounds(Min, Max);
	 float	TileWidth = Max.X - Min.X;
	
	 //Start creating tiles
	 Map.SetNum(Y);
	 for (int32 y = 0; y < Map.Num(); ++y)
	 {
	 	Map[y].SetNum(X);
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
	 		if (FMath::RandRange(0,1))
	 		{
	 			TileActor->bIsWater = true;
	 			TileActor->ChangeMaterial(3);
	 		}
	 		TileActor->Pos.Y = y;
	 		TileActor->Pos.X = x;
	 		Map[y][x] = TileActor;
	 	}
	 }
}

void	UHexMap::SummonPawns(int32 Amount)
{
	if (!PawnBluePrint)
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nUHexMap::SummonPawn : No Blueprint for pawn\n========================================================="));
		return ;
	}
	PlayerPawns.SetNum(Amount);
	for (int i = 0; i < Amount; ++i)
	{
		FIntVector2 MapPos(FMath::RandRange(0,Map.Num() - 1), FMath::RandRange(0,Map[0].Num() - 1));
		while (Map[MapPos.Y][MapPos.X]->TileOwner)
		{
			MapPos = FIntVector2(FMath::RandRange(0,Map.Num() - 1), FMath::RandRange(0,Map[0].Num() - 1));
		}
		FVector	Loc(0.f, 0.f, 200.f);
		PlayerPawns[i] = GetWorld()->SpawnActor<APawnBase>(PawnBluePrint, Loc, FRotator::ZeroRotator);
		if (!PlayerPawns[i])
		{
			UE_LOG(LogTemp, Error, TEXT("UHexMap::SummonPawn : Failed"));
		}
		PlayerPawns[i]->SetActorLocation(Map[MapPos.Y][MapPos.X]->GetActorLocation());
		PlayerPawns[i]->MarkPackageDirty();
		Map[MapPos.Y][MapPos.X]->Conqured(PlayerPawns[i]);
	}
}

void UHexMap::BeginDestroy()
{
	UObject::BeginDestroy();
	UE_LOG(LogTemp, Error, TEXT("UHexMap::BeginDestroy : Destroyed"));

}
