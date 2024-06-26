// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"

#include "Conquest/FightGameMode.h"
#include "Kismet/GameplayStatics.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}



// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	FightGameMode = Cast<AFightGameMode>(UGameplayStatics::GetGameInstance(this));
}

void UHealthComponent::ReciveDamage(float Damage)
{

	Health -= Damage;
	if (Health <= 0)
	{
		FightGameMode->ActorDied(GetOwner());
	}
}

// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

