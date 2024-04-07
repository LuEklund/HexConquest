// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawnController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Blueprint/UserWidget.h"
#include "Conquest/GameModes/ConquestGameMode.h"
#include "Conquest/Pawns/PawnBase.h"


void APlayerPawnController::BeginPlay()
{
	Super::BeginPlay();
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
	bEnableClickEvents = true;

	if (WidgetHUDClass)
	{
		HUDWidget = CreateWidget<UUserWidget>(GetWorld(), WidgetHUDClass);
		HUDWidget->AddToViewport();
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nNo BP WIDGET class in APlayerPawnController\n========================================================="));
	}

}



void APlayerPawnController::PromptTile()
{
	if (!WidgetClass)
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nNo BP WIDGET class in APlayerPawnController\n========================================================="));
		return ;
	}
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

void APlayerPawnController::TogglePlayerTurn(bool bCanPlay)
{
	if (bCanPlay)
	{
		bShowMouseCursor = true;
		bEnableMouseOverEvents = true;
		bEnableClickEvents = true;
	}
	else
	{
		bShowMouseCursor = false;
		bEnableMouseOverEvents = false;
		bEnableClickEvents = false;
	}
}


void APlayerPawnController::PossesPawn(APawnBase *PawnToPosses)
{
	if (!PawnToPosses)
	{
		UE_LOG(LogTemp, Display, TEXT("NO pawn to posses"));

		return ;
	}
	Possess(PawnToPosses);
	if(UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(this->GetLocalPlayer()))
	{
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("UEnhancedInputLocalPlayerSubsystem: FALIED"));
	}
	if (UEnhancedInputComponent *Input = Cast<UEnhancedInputComponent>(InputComponent))
	{
		Input->BindAction(InputMove, ETriggerEvent::Triggered, this, &APlayerPawnController::EnhancedInputMove);
		Input->BindAction(InputZoom, ETriggerEvent::Triggered, this, &APlayerPawnController::EnhancedInputZoom);
		Input->BindAction(InputPlayerSwap, ETriggerEvent::Triggered, this, &APlayerPawnController::EnhancedInputPlayerSwap);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("UEnhancedInputComponent: FALIED"));
	}
}


void APlayerPawnController::EnhancedInputZoom(const FInputActionValue& value)
{
	if (APawnBase *ControlledPawn = GetPawn<APawnBase>())
	{
		ControlledPawn->AddInputZoom(value.Get<float>());
		
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("APlayerPawnController::EnhancedInputZoom: NO Pawn controlled"));
	}
		
}

void APlayerPawnController::EnhancedInputMove(const FInputActionValue& value)
{
	//Gets input values
	FVector2d MovementVector = value.Get<FVector2d>();

	if (APawnBase *ControlledPawn = GetPawn<APawnBase>())
	{
		ControlledPawn->Move( value.Get<FVector2d>());
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("APlayerPawnController::EnhancedInputMove: NO MOVE"));
	}

}

void APlayerPawnController::EnhancedInputPlayerSwap(const FInputActionValue& value)
{
	GetWorld()->GetAuthGameMode<AConquestGameMode>()->SwapPlayer(value.Get<float>());
}


