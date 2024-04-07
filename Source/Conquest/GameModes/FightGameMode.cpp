// Fill ut your copyright notice in the Description page of Project Settings.


#include "FightGameMode.h"

#include "../ConquestGameInstance.h"
#include "../Player/FightPlayerController.h"
#include "../State/FightGameState.h"

void AFightGameMode::BeginPlay()
{
	Super::BeginPlay();
	GameInstance = Cast<UConquestGameInstance>(GetGameInstance());
	FightGameState = Cast<AFightGameState>(GetGameState<AFightGameState>());
	Controller = Cast<AFightPlayerController>(GetWorld()->GetFirstPlayerController());

	//Create Player Troops
	GameInstance->PlayerTroops = 8;
	Soldiers.SetNum(GameInstance->PlayerTroops);
	for (int32 i = 0; i < GameInstance->PlayerTroops; ++i)
	{
		//X = Forward, Y = Right, Z = Up
		FVector	Loc(i * 10.f, -350.f, i * 50.f);
		FRotator Rot(0.f,90.f,0.f);
		ABaseSoldier *Soldier = Cast<ABaseSoldier>(GetWorld()->SpawnActor<ABaseSoldier>(SoldierClass, Loc, Rot));
		Soldier->StartPostion = Loc;
		Soldiers[i] = Soldier;
	}

	//Create Enemy troops
	EnemySoldiers.SetNum(FightGameState->EnemyTroops);
	for (int32 i = 0; i < FightGameState->EnemyTroops; ++i)
	{
		//X = Forward, Y = Right, Z = Up
		FVector	Loc(i * 10.f, 350.f, i * 50.f);
		FRotator Rot(0.f,90.f,0.f);
		ABaseSoldier *Soldier = Cast<ABaseSoldier>(GetWorld()->SpawnActor<ABaseSoldier>(EnenmySoldierClass, Loc, Rot));
		Soldier->StartPostion = Loc;
		EnemySoldiers[i] = Soldier;
	}
}

void AFightGameMode::MeeleAttack(bool isPlayer)
{
	if (isPlayer)
	{
		if (Soldiers.Num() < 1)
		{
			GameOver(false);
			return ;
		}
		for (ABaseSoldier *Soldier : Soldiers)
		{
			TArray<ABaseSoldier *> Attackable = EnemySoldiers.FilterByPredicate([](ABaseSoldier *Sol) {return (Sol->bAlive);});
			if (Attackable.Num() < 1)
			{
				GameOver(true);
			}
			else
			{
				int32 RandomIndex = FMath::RandRange(0, Attackable.Num() - 1);
				ABaseSoldier *TargetSoldier = Attackable[RandomIndex];
				Soldier->InitiateAttack(TargetSoldier);
				// Soldier->Attack(TargetSoldier);
			}
		}
	}
}

void AFightGameMode::ActorDied(AActor* Actor)
{
	if (ABaseSoldier *Soldier = Cast<ABaseSoldier>(Actor))
	{
		Soldier->bAlive = false;
		Soldier->SetActorHiddenInGame(true);
		// Soldier->Destroy();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nAFightGameMode: DO not handle this type of AActor Death\n========================================================="));
	}
}

void AFightGameMode::GameOver(bool Victory)
{
	FightGameState->bWon = Victory;
	GameInstance->MapTransition(FName("Default"));
}
