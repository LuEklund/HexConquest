// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "FightPlayerPawn.generated.h"

UCLASS()
class CONQUEST_API AFightPlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AFightPlayerPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;


	//==========================================Enhanced Input===========================================
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Mapping Context
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	class UInputMappingContext	*InputMappingContext;

	//Input
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Input")
	class UInputAction	*InputDoStuff;

	void	EnhancedInput(const struct FInputActionValue& Value);
	//==========================================Enhanced Input===========================================


	UPROPERTY(EditAnywhere, Category="Base")
	class UCapsuleComponent	*CapsuleComponent;

	UPROPERTY(EditAnywhere, Category="Base")
	class USpringArmComponent	*SpringArmComponent;

	UPROPERTY(EditAnywhere, Category="Base")
	class UCameraComponent		*CameraComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


};
