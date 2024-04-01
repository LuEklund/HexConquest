// Fill ut your copyright notice in the Description page of Project Settings.


#include "FightGameMode.h"

#include "ConquestGameInstance.h"
#include "Player/FightPlayerController.h"

void AFightGameMode::BeginPlay()
{
	Super::BeginPlay();
	GameInstance = Cast<UConquestGameInstance>(GetGameInstance());
	Controller = Cast<AFightPlayerController>(GetWorld()->GetFirstPlayerController());

	//Create Troops
	GameInstance->PlayerTroops = 8;
	Soldiers.SetNum(GameInstance->PlayerTroops);
	for (int32 i = 0; i < GameInstance->PlayerTroops; ++i)
	{
		FVector	Loc(i * 100.f, 0.f, i * 50.f);
		FRotator Rot(0.f,90.f,0.f);
		ABaseSoldier *Soldier = Cast<ABaseSoldier>(GetWorld()->SpawnActor<ABaseSoldier>(SoldierClass, Loc, Rot));
		Soldiers[i] = Soldier;
	}
}
