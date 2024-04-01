// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSoldier.h"

// Sets default values
ABaseSoldier::ABaseSoldier()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABaseSoldier::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseSoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

