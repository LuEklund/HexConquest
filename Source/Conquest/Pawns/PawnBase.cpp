// Fill out your copyright notice in the Description page of Project Settings.


#include "PawnBase.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APawnBase::APawnBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base"));
	SetRootComponent(Base);
	

	// Setup Camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));
	SpringArm->SetupAttachment(RootComponent);
	SpringArm->bEnableCameraLag = false;
	SpringArm->TargetArmLength = 700.0f;

	
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(SpringArm, USpringArmComponent::SocketName);
	Camera->bUsePawnControlRotation = false;

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("FloatingMovementComponent"));
	MovementComponent->UpdatedComponent = RootComponent;

}

// Called when the game starts or when spawned
void APawnBase::BeginPlay()
{	
	Super::BeginPlay();
	
}

// Called every frame
void APawnBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APawnBase::AddInputZoom(const float zoom)
{
	float newDistance = FMath::Clamp(SpringArm->TargetArmLength - zoom * 100.f, 0.f, 1750.f);
	SpringArm->TargetArmLength = newDistance;
}

void APawnBase::Move(FVector2D Vector)
{
	float speed = 1000.f;

	float dt = UGameplayStatics::GetWorldDeltaSeconds(this->GetWorld());
	// Convert the 2D vector to a 3D vector, assuming no Z movement
	FVector DeltaPos(Vector.X, Vector.Y, 0);
    
	// Scale the vector by the desired movement speed
	DeltaPos *= dt * speed;
	SpringArm->AddRelativeLocation(DeltaPos);
}

void APawnBase::BeginDestroy()
{
	Super::BeginDestroy();
	UE_LOG(LogTemp, Error, TEXT("APawnBase::BeginDestroy : Destroyed"));

}

