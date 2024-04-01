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
		//Ask to fight
		GameMode->PromptToFight(this);
		//ButtonPressed(true);
		//yes -> Fight -> Move if Victory
		//NO -> dont move
	}
	else
	{
		GameMode->MovePawnTo(this);
	}
	UE_LOG(LogTemp, Display, TEXT("Pressed"));
}

void ATile::NotifyActorBeginCursorOver()
{
	Super::NotifyActorBeginCursorOver();

}

void ATile::NotifyActorEndCursorOver()
{
	Super::NotifyActorEndCursorOver();

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

