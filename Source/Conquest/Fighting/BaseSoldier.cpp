// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseSoldier.h"

#include "Components/CapsuleComponent.h"
#include "PaperFlipbookComponent.h"
// Sets default values
ABaseSoldier::ABaseSoldier()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule"));
	SetRootComponent(CapsuleComponent);
	PaperFlipbookComponent = CreateDefaultSubobject<UPaperFlipbookComponent>(TEXT("Sprite FLipBook"));
	PaperFlipbookComponent->SetupAttachment(RootComponent);

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

}

