// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"

UENUM()
enum ETileOwner : int8
{
	None,
	Player,
	Enemy,
	Water,
};
UCLASS()
class CONQUEST_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyActorOnClicked(FKey ButtonPressed) override;
	virtual void NotifyActorBeginCursorOver() override;
	virtual void NotifyActorEndCursorOver() override;

	void	Conqured(bool bWasPlayer);
	void	ChangeMaterialEdge(int32 mateiral);
	void	ChangeMaterial(int32 mateiral);

	ETileOwner	TileOwner = ETileOwner::None;
	bool		bIsWater = false;
	FIntVector2	Pos;
	
	UPROPERTY(EditAnywhere, Category="Base")
	UStaticMeshComponent	*Tile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Material")
	UMaterialInterface	*FreeTileMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Material")
	UMaterialInterface	*WaterTileMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Material")
	UMaterialInterface	*YourTileMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Material")
	UMaterialInterface	*EnemyTileMaterial;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Material")
	UMaterialInterface	*HoverOutline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Material")
	UMaterialInterface	*PressedOutline;

	UPROPERTY()
	UMaterialInterface	*DefaultOutline;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};
