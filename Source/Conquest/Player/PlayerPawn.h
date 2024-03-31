// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerPawn.generated.h"


UCLASS()
class CONQUEST_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category="Base")
	class UCapsuleComponent	*CapsuleComponent;

	UPROPERTY(EditAnywhere, Category="Base")
	class USpringArmComponent	*SpringArm;
	
	UPROPERTY(EditAnywhere, Category="Base")
	class UCameraComponent		*Camera;

	UPROPERTY(EditAnywhere, Category="Input")
	float		Speed = 250.f;





	//============[Enhanced Input]======================================

	void	EnhancedInputZoom(const struct FInputActionValue& value);
	
	void	EnhancedInputMove(const struct FInputActionValue& value);
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//The mapping context
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enhanced Input")
	class UInputMappingContext *InputMappingContext;

	//Zoom
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enhanced Input")
	class UInputAction *InputZoom;

	//Movement
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Enhanced Input")
	class UInputAction *InputMove;

	//===================================================================

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
