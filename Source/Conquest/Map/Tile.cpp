// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"
#include "../ConquestGameMode.h"

// Sets default values
ATile::ATile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Tile = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Tile"));
	SetRootComponent(Tile);
	DefaultOutline = Tile->GetMaterial(1);
}

// Called when the game starts or when spawned
void ATile::BeginPlay()
{
	Super::BeginPlay();
	if (TileOwner == ETileOwner::Enemy)
	{
		Tile->SetMaterial(0, EnemyTileMaterial);
	}
	else if (TileOwner == ETileOwner::Player)
	{
		Tile->SetMaterial(0, YourTileMaterial);
	}
	else if (TileOwner == ETileOwner::Water)
	{
		Tile->SetMaterial(0, WaterTileMaterial);
	}
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATile::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	
	AConquestGameMode	*GameMode = Cast<AConquestGameMode>(GetWorld()->GetAuthGameMode());
	if (TileOwner == ETileOwner::Enemy)
	{
		GameMode->PromptToFight(this);
	}
	else
	{
		if (TileOwner == ETileOwner::None)
		{
			Conqured(true);
		}
		GameMode->MovePawnTo(this);
		GameMode->clearWidget();
	}
	Tile->SetMaterial(1,PressedOutline);

}

void ATile::NotifyActorBeginCursorOver()
{
	Super::NotifyActorBeginCursorOver();
	if (Tile->GetMaterial(1) != PressedOutline)
	{
		Tile->SetMaterial(1,HoverOutline);
	}

}

void ATile::NotifyActorEndCursorOver()
{
	Super::NotifyActorEndCursorOver();
	if (Tile->GetMaterial(1) != PressedOutline)
	{
		Tile->SetMaterial(1, DefaultOutline);
	}

}

void ATile::Conqured(bool bWasPlayer)
{
	if (bWasPlayer)
	{
		Tile->SetMaterial(0, YourTileMaterial);
		TileOwner = ETileOwner::Player;
	}
	else
	{
		Tile->SetMaterial(0, EnemyTileMaterial);
		TileOwner = ETileOwner::Enemy;
	}
}



void ATile::ChangeMaterialEdge(int32 material)
{
	switch (material)
	{
	case 0:
		Tile->SetMaterial(1,DefaultOutline);
		break;
	case 1:
		Tile->SetMaterial(1,YourTileMaterial);
		break;
	case 2:
		Tile->SetMaterial(1,EnemyTileMaterial);
		break;
	case 3:
		Tile->SetMaterial(1,WaterTileMaterial);
		break;
	default:
		break;
	}

}

void ATile::ChangeMaterial(int32 mateiral)
{
	switch (mateiral)
	{
	case 0:
		Tile->SetMaterial(0,DefaultOutline);
		break;
	case 1:
		Tile->SetMaterial(0,YourTileMaterial);
		break;
	case 2:
		Tile->SetMaterial(0,EnemyTileMaterial);
		break;
	case 3:
		Tile->SetMaterial(0,WaterTileMaterial);
		break;
	default:
		break;
	}
}

