// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerPawn.h"
#include "InputActionValue.h"

#include "Components/CapsuleComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Base Capsule"));
	SetRootComponent(CapsuleComponent);
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm->SetupAttachment(RootComponent);
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm);
	

}


// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}




// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if(APlayerController *PlayerController =  Cast<APlayerController>(Controller))
	{
		if(UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PlayerController->GetLocalPlayer()))
		{
	
			Subsystem->AddMappingContext(InputMappingContext, 0);
		}
		else
		{
			UE_LOG(LogTemp, Display, TEXT("UEnhancedInputLocalPlayerSubsystem: FALIED"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("APlayerController: FALIED"));
	}
	if (UEnhancedInputComponent *Input = Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		Input->BindAction(InputMove, ETriggerEvent::Triggered, this, &APlayerPawn::EnhancedInputMove);
		Input->BindAction(InputZoom, ETriggerEvent::Triggered, this, &APlayerPawn::EnhancedInputZoom);
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("UEnhancedInputComponent: FALIED"));

	}

}


void APlayerPawn::EnhancedInputZoom(const FInputActionValue& value)
{
	float zoom = value.Get<float>();
	float newDistance = FMath::Clamp(SpringArm->TargetArmLength - zoom * 10.f, 0.f, 1750.f);
	SpringArm->TargetArmLength = newDistance;
	UE_LOG(LogTemp, Display, TEXT("LOL %f, %f"), zoom, newDistance);
}

void APlayerPawn::EnhancedInputMove(const FInputActionValue& value)
{
	//Gets input values
	FVector2d moveVector = value.Get<FVector2d>();

	//create our delta position to add
	float	dt = UGameplayStatics::GetWorldDeltaSeconds(this->GetWorld());
	FVector	DeltaPos(moveVector.X * dt * Speed, moveVector.Y * dt * Speed, 0);
	AddActorLocalOffset(DeltaPos, true);
}


