// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CONQUEST_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, Category="Health")
	float	MaxHealth = 10.f;

	UPROPERTY(EditAnywhere, Category="Health")
	float Health = 0.f;

	class AFightGameMode	*FightGameMode;
	void	ReciveDamage(float Damage);
	

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


		
};
