// Fill out your copyright notice in the Description page of Project Settings.


#include "Tile.h"
#include "../Player/PlayerPawnController.h"

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
	
}

// Called every frame
void ATile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATile::NotifyActorOnClicked(FKey ButtonPressed)
{
	Super::NotifyActorOnClicked(ButtonPressed);
	APlayerPawnController *PlayerController = Cast<APlayerPawnController>(GetWorld()->GetFirstPlayerController());
	PlayerController->MovePawnTo(GetActorLocation());
	UE_LOG(LogTemp, Display, TEXT("Pressed"));
}

void ATile::NotifyActorBeginCursorOver()
{
	Super::NotifyActorBeginCursorOver();
	UE_LOG(LogTemp, Display, TEXT("BEGIN HOVER"));

}

void ATile::NotifyActorEndCursorOver()
{
	Super::NotifyActorEndCursorOver();
	UE_LOG(LogTemp, Display, TEXT("END Hover"));

}

