// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSoldier.generated.h"

UCLASS()
class CONQUEST_API ABaseSoldier : public AActor
{
	GENERATED_BODY()

private:
	UPROPERTY()
	ABaseSoldier *Attacking;

public:	
	// Sets default values for this actor's properties
	ABaseSoldier();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void InitiateAttack(ABaseSoldier* BaseSoldier);

	UPROPERTY(EditAnywhere, Category="Base");
	class UCapsuleComponent	*CapsuleComponent;

	UPROPERTY(EditAnywhere, Category="Health")
	class UHealthComponent	*HealthComponent;

	UPROPERTY(EditAnywhere, Category="Sprite")
	class UPaperFlipbookComponent	*PaperFlipbookComponent;

	void ReceiveDamage(float X);
	void Attack(ABaseSoldier *Victim);

	bool	bAlive = true;
	FVector	StartPostion;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
