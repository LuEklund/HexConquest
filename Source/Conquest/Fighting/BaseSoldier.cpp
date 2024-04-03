// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSoldier.h"

#include "Components/CapsuleComponent.h"
#include "PaperFlipbookComponent.h"
#include "Conquest/Components/HealthComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
// Sets default values
ABaseSoldier::ABaseSoldier()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(CapsuleComponent);
	PaperFlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite FLipBook"));
	PaperFlipbookComponent->SetupAttachment(RootComponent);

	
	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("Health"));

	Attacking = nullptr;

}



// Called when the game starts or when spawned
void ABaseSoldier::BeginPlay()
{
	Super::BeginPlay();
	PaperFlipbookComponent->Play();


}


// Called every frame
void ABaseSoldier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Attacking)
	{
		FVector	Direction = Attacking->GetActorLocation() - this->GetActorLocation();
		if (FVector::Dist(Attacking->GetActorLocation(),  this->GetActorLocation()) > 100)
		{
			Direction.Normalize();
			FVector NewLocation = GetActorLocation() + Direction * DeltaTime * 1000.f;
			this->SetActorLocation(NewLocation);
		}
		else
		{
			this->Attack(Attacking);
			Attacking = nullptr;
		}
	}
	else if (FVector::Dist(this->GetActorLocation(),  this->StartPostion) > 100)
	{
		FVector	Direction = this->StartPostion - this->GetActorLocation();
		Direction.Normalize();
		FVector NewLocation = GetActorLocation() + Direction * DeltaTime * 1000.f;
		this->SetActorLocation(NewLocation);
	}

}

void ABaseSoldier::InitiateAttack(ABaseSoldier* BaseSoldier)
{
	Attacking = BaseSoldier;
}


void ABaseSoldier::ReceiveDamage(float X)
{
	HealthComponent->ReciveDamage(X);
}

void ABaseSoldier::Attack(ABaseSoldier *Victim)
{
	if (ABaseSoldier *SoliderVictim = Cast<ABaseSoldier>(Victim))
	{
		SoliderVictim->ReceiveDamage(1.f);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("========================================\nABaseSoldier: Cannot attack this type of AActor\n========================================================="));
	}
}

