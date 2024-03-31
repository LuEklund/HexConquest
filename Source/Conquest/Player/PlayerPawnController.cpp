// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnController.h"
#include "../Pawns/PawnBase.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "../ConquestGameInstance.h"


void APlayerPawnController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
	bEnableClickEvents = true;
	GameInstance = Cast<UConquestGameInstance>(GetGameInstance());
	if (GameInstance)
	{
		TempTileCord = GameInstance->TempHexCords;
		TroopsAmount = GameInstance->PlayerTroops;
		WonBattle(GameInstance->bWon);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nAPlayerPawnController: No Game Instance\n========================================================="));
	}
}

void APlayerPawnController::MovePawnTo(const FVector& Vector)
{
	HexPawn->SetActorLocation(Vector);
}

void APlayerPawnController::CreatePawn(const FVector& Vector)
{
	if (!PawnBluePrintClass)
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nNo BP Tile class in PlayerPawnController\n========================================================="));
		return ;
	}
	FVector	Loc(0.f, 0.f, 200.f);
	AActor *test = GetWorld()->SpawnActor<APawnBase>(PawnBluePrintClass, Loc, FRotator::ZeroRotator);
	if (!test)
	{
		UE_LOG(LogTemp, Error, TEXT("APlayerPawnController: PawnBluePrintClass"));
	}
	HexPawn = Cast<APawnBase>(test);
	MovePawnTo(Vector);
}

void APlayerPawnController::PromptToFight(const FVector& Vector)
{
	if (!WidgetClass)
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nNo BP WIDGET class in APlayerPawnController\n========================================================="));
		return ;
	}
	TempTileCord = Vector;
	if (!PromptWidget)
	{
		PromptWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
	}
	if(PromptWidget->IsInViewport())
	{
		PromptWidget->RemoveFromParent();
	}
	PromptWidget->AddToViewport();
}

void APlayerPawnController::HandleConflict(bool bFight)
{

	if (bFight)
	{
		UE_LOG(LogTemp, Warning, TEXT("FIGHT2"));
		if (GameInstance)
		{
			GameInstance->MapTransition(FName("Fighting"));
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("NO GAME INSTANCE"));
		}
	}
	else
	{
		TempTileCord = FVector::Zero();
		UE_LOG(LogTemp, Warning, TEXT("NO FIGHT"));
	}
	PromptWidget->RemoveFromParent();
}

void	APlayerPawnController::WonBattle(bool bVictory)
{
	if (bVictory)
	{
		MovePawnTo(TempTileCord);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("We gonna move LOL"));
	}
}

