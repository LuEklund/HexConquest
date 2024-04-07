// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Pawn.h"
#include "PawnBase.generated.h"

UCLASS()
class CONQUEST_API APawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APawnBase();

	UPROPERTY(EditAnywhere, Category="Base")
	UStaticMeshComponent	*Base;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Base")
	class USceneComponent	*Scene;
	
	UPROPERTY(EditAnywhere, Category="Base")
	class USpringArmComponent	*SpringArm;
	
	UPROPERTY(EditAnywhere, Category="Base")
	class UCameraComponent		*Camera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Base")
	class UFloatingPawnMovement	*MovementComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Material")
	UMaterialInterface	*ConquerColor;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void AddInputZoom(const float);
	void Move(FVector2D Vector);
	virtual void BeginDestroy() override;
};
