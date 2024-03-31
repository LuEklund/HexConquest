// Fill out your copyright notice in the Description page of Project Settings.


#include "FightPlayerPawn.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "FightPlayerController.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Conquest/ConquestGameInstance.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFightPlayerPawn::AFightPlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(CapsuleComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring arm"));
	SpringArmComponent->SetupAttachment(RootComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	CameraComponent->SetupAttachment(SpringArmComponent);

}


// Called when the game starts or when spawned
void AFightPlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFightPlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AFightPlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if(APlayerController *PlayerController = Cast<APlayerController>(Controller))
	{
		if (UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("UEnhancedInputLocalPlayerSubsystem: FALIED"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AFightPlayerPawn: FALIED 1"));
	}
	if (UEnhancedInputComponent *Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(InputDoStuff, ETriggerEvent::Triggered, this, &AFightPlayerPawn::EnhancedInput);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AFightPlayerPawn: FALIED 2"));
	}
}

void AFightPlayerPawn::EnhancedInput(const FInputActionValue& Value)
{
	AFightPlayerController *PlayerController = Cast<AFightPlayerController>(Controller);
	PlayerController->bWon = true;
	PlayerController->GameInstance->MapTransition(FName("Default"));
}
