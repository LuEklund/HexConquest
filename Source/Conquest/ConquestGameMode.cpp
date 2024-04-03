// Fill out your copyright notice in the Description page of Project Settings.


#include "ConquestGameMode.h"

#include "ConquestGameInstance.h"
#include "ConquestGameState.h"
#include "Blueprint/UserWidget.h"
#include "Map/Tile.h"
#include "Player/PlayerPawnController.h"
#include "State/ConquestPlayerState.h"


void AConquestGameMode::BeginPlay()
{
	Super::BeginPlay();
	GameInstance = Cast<UConquestGameInstance>(GetGameInstance());
	ConquestGameState = Cast<AConquestGameState>(GetGameState<AConquestGameState>());
	Controller = Cast<APlayerPawnController>(GetWorld()->GetFirstPlayerController());
	ConquestPlayerState = Cast<AConquestPlayerState>(Controller->GetPlayerState<AConquestPlayerState>());	if(!ConquestGameState)
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nAConquestGameMode: No Game State\n========================================================="));
		return ;
	}

	if (GameInstance)
	{
		// TempTileCord = GameInstance->TempHexCords;
		// TroopsAmount = GameInstance->PlayerTroops;
		
		//Setup The map
		ConquestGameState->SetupHexMap(GameInstance->HexMapData);
		//Convert player tile to owning
		ConquestGameState->GetTile(GameInstance->PlayerBaseTile.PositionInMap)->Conqured(true);
		//Create Player pawn
		AActor *BoardPawn = ConquestGameState->CreatePawn(ConquestGameState->GetTile(GameInstance->PlayerBaseTile.PositionInMap)->GetActorLocation());
		MovePawnTo(Cast<ATile>(ConquestGameState->GetTile(GameInstance->CurrentPlayerPos.PositionInMap)));
		//Put player pawn on the right spot
		WonBattle(GameInstance->bWon);
		//Move Camera to Player Pawn
		FVector	Loc(BoardPawn->GetActorLocation().X, BoardPawn->GetActorLocation().Y, Controller->GetPawn()->GetActorLocation().Z);
		Controller->GetPawn()->SetActorLocation(Loc);
		
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nAConquestGameMode: No Game Instance\n========================================================="));
	}
}


void AConquestGameMode::MovePawnTo(ATile *HexTile)
{
	ConquestGameState->GetTile(ConquestGameState->TryToMoveToTile.PositionInMap)->ChangeMaterial();
	ConquestGameState->TryToMoveToTile.PositionInMap = HexTile->Pos;
	ConquestGameState->TryToMoveToTile.bEnemy = HexTile->bIsEnemy;
	ConquestGameState->CurrentPlayerTilePos.PositionInMap = HexTile->Pos;
	ConquestGameState->CurrentPlayerTilePos.bEnemy = HexTile->bIsEnemy;
	ConquestGameState->MovePawnTo(HexTile->GetActorLocation());

}



void AConquestGameMode::PromptToFight(ATile *HexTile)
{
	//save where to move stats.
	ConquestGameState->GetTile(ConquestGameState->TryToMoveToTile.PositionInMap)->ChangeMaterial();
	ConquestGameState->TryToMoveToTile.PositionInMap = HexTile->Pos;
	ConquestGameState->TryToMoveToTile.bEnemy = HexTile->bIsEnemy;
	Controller->PromptToFight();
}

void AConquestGameMode::clearWidget()
{
	if (Controller->PromptWidget && Controller->PromptWidget->IsInViewport())
	{
		Controller->PromptWidget->RemoveFromParent();
	}
}


void AConquestGameMode::HandleConflict(bool bFight)
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
		UE_LOG(LogTemp, Warning, TEXT("NO FIGHT"));
	}
	Controller->PromptWidget->RemoveFromParent();
}

void	AConquestGameMode::WonBattle(bool bVictory)
{
	if (bVictory)
	{
		ATile *VictoryTile = Cast<ATile>(ConquestGameState->GetTile(GameInstance->TryToMoveToTile.PositionInMap));
		VictoryTile->Conqured(true);
		MovePawnTo(VictoryTile);
		
	}
	else
	{
		MovePawnTo(Cast<ATile>(ConquestGameState->GetTile(GameInstance->CurrentPlayerPos.PositionInMap)));
	}
}


