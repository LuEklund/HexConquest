// Fill out your copyright notice in the Description page of Project Settings.


#include "ConquestGameMode.h"

#include "../ConquestGameInstance.h"
#include "../State/ConquestGameState.h"
#include "../AI/AIControllerHexConquest.h"
#include "Blueprint/UserWidget.h"
#include "../Map/Tile.h"
#include "../Player/PlayerPawnController.h"
#include "../State/ConquestPlayerState.h"
#include "../Pawns/PawnBase.h"
#include "Conquest/Map/HexMap.h"
#include "Kismet/GameplayStatics.h"


void AConquestGameMode::BeginPlay()
{
	Super::BeginPlay();
	GameInstance = Cast<UConquestGameInstance>(UGameplayStatics::GetGameInstance(this));
	ConquestGameState = Cast<AConquestGameState>(GetGameState<AConquestGameState>());
	Controller = Cast<APlayerPawnController>(GetWorld()->GetFirstPlayerController());
	ConquestPlayerState = Cast<AConquestPlayerState>(Controller->GetPlayerState<AConquestPlayerState>());
	HexMap = GameInstance->GetHexMap();
	UE_LOG(LogTemp, Warning, TEXT("=========================\nGameMode BeginPlay AMp and play size: %d, %d\n===================="), HexMap->Map.Num(), HexMap->PlayerPawns.Num());


	
	//Convert player tile to owning
	// ConquestGameState->GetTile(GameInstance->PlayerBaseTile.PositionInMap)->Conqured(true);
	// //Create Player pawn
	// AActor *BoardPawn = ConquestGameState->CreatePawn(ConquestGameState->GetTile(GameInstance->PlayerBaseTile.PositionInMap)->GetActorLocation());
	// MovePawnTo(Cast<ATile>(ConquestGameState->GetTile(GameInstance->CurrentPlayerPos.PositionInMap)));
	// //Put player pawn on the right spot
	// WonBattle(GameInstance->bWon);
	// //Move Camera to Player Pawn
	// FVector	Loc(BoardPawn->GetActorLocation().X, BoardPawn->GetActorLocation().Y, Controller->GetPawn()->GetActorLocation().Z);
	// Controller->GetPawn()->SetActorLocation(Loc);
	//
	// //Create AI
	// ConquestGameState->CreateAIPawn(ConquestGameState->GetTile(GameInstance->CurrentAITile.PositionInMap)->GetActorLocation());
	if (HexMap)
	{
		if(HexMap->PlayerPawns.Num())
		{
			if (HexMap->PlayerPawns[0])
			{
				if (!Controller)
				{
					UE_LOG(LogTemp, Error, TEXT("========================================\nGameMode No Controller\n========================================================="));

				}
				else
				{
				Controller->PossesPawn(HexMap->PlayerPawns[0]);
					
				}
				
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("========================================\nGameMode No Specfic playerd\n========================================================="));

			}
		}
		else
		{
			
		UE_LOG(LogTemp, Error, TEXT("========================================\nGameMode No Players\n========================================================="));
		}

	}
	else
	{
		
	UE_LOG(LogTemp, Error, TEXT("========================================\nGameMode No Map\n========================================================="));
	}

}


void AConquestGameMode::MovePawnTo(ATile *HexTile)
{
	// ConquestGameState->GetTile(ConquestGameState->TryToMoveToTile.PositionInMap)->ChangeMaterialEdge(0);
	// ConquestGameState->TryToMoveToTile.PositionInMap = HexTile->Pos;
	// ConquestGameState->TryToMoveToTile.TileOwner = HexTile->TileOwner;
	// ConquestGameState->CurrentPlayerTilePos.PositionInMap = HexTile->Pos;
	// ConquestGameState->CurrentPlayerTilePos.TileOwner = HexTile->TileOwner;
	// ConquestGameState->MovePawnTo(HexTile->GetActorLocation());
}



void AConquestGameMode::PromptTile(ATile *HexTile)
{
	//save where to move stats.
	// ConquestGameState->GetTile(ConquestGameState->TryToMoveToTile.PositionInMap)->ChangeMaterialEdge(0);
	// ConquestGameState->TryToMoveToTile.PositionInMap = HexTile->Pos;
	// ConquestGameState->TryToMoveToTile.TileOwner = HexTile->TileOwner;
	Controller->PromptTile();
}

void AConquestGameMode::clearWidget()
{
	if (Controller->PromptWidget && Controller->PromptWidget->IsInViewport())
	{
		Controller->PromptWidget->RemoveFromParent();
	}
}

void AConquestGameMode::SwapPlayer(float Swap)
{
	int32 index = HexMap->PlayerPawns.Find(Controller->GetPawn<APawnBase>());
	if (Swap < 0)
	{
		index <= 0 ?  index = HexMap->PlayerPawns.Num() -1 : index--;
	}
	else
	{
		index >= HexMap->PlayerPawns.Num() - 1 ? index = 0 : index++;
	}
	Controller->Possess(Cast<APawn>(HexMap->PlayerPawns[index]));
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
		// ATile *VictoryTile = Cast<ATile>(ConquestGameState->GetTile(GameInstance->TryToMoveToTile.PositionInMap));
		// VictoryTile->Conqured(true);
		// MovePawnTo(VictoryTile);
		
	}
	else
	{
		// MovePawnTo(Cast<ATile>(ConquestGameState->GetTile(GameInstance->CurrentPlayerPos.PositionInMap)));
	}
}

void AConquestGameMode::AITurn()
{
	
}


