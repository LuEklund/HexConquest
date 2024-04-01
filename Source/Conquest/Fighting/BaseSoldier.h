// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseSoldier.generated.h"

UCLASS()
class CONQUEST_API ABaseSoldier : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseSoldier();

	UPROPERTY(EditAnywhere, Category="Base");
	class UCapsuleComponent	*CapsuleComponent;

	UPROPERTY(EditAnywhere, Category="Sprite")
	class UPaperFlipbookComponent	*PaperFlipbookComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
