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
	if (bIsEnemy)
	{
		Tile->SetMaterial(0, EnemyTileMaterial);
	}
	else
	{
		Tile->SetMaterial(0, YourTileMaterial);
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
	if (bIsEnemy)
	{
		GameMode->PromptToFight(this);
	}
	else
	{
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
		bIsEnemy = false;
	}
	else
	{
		Tile->SetMaterial(0, EnemyTileMaterial);
	}
}

void ATile::ChangeMaterial()
{
	
	Tile->SetMaterial(1,DefaultOutline);

}

