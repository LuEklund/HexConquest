// Fill out your copyright notice in the Description page of Project Settings.


#include "SaveGameConquest.h"

#include "ConquestGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Map/HexMap.h"

// void USaveGameConquest::LoadHexMap()
// {
// 	UConquestGameInstance *GameInstance = Cast<UConquestGameInstance>(UGameplayStatics::GetGameInstance(this));
// 	USaveGameConquest* LoadedGame = Cast<USaveGameConquest>(UGameplayStatics::LoadGameFromSlot("Default", 0));
// 	if (!GameInstance)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("0=============================\n USaveGameConquest::LoadHexMap : No GameInstance\n0=================================="));
// 		return ;
// 	}
// 	if (!LoadedGame)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("0=============================\n USaveGameConquest::LoadHexMap : No LoadedGame\n0=================================="));
// 		return ;
// 	}
// 	GameInstance->HexMap->PlayerPawns = LoadedGame->PlayerPawns;
// 	GameInstance->HexMap->Map = LoadedGame->Map;
// }
//
// void USaveGameConquest::SaveHexMap()
// {
// 	UConquestGameInstance *GameInstance = Cast<UConquestGameInstance>(UGameplayStatics::GetGameInstance(this));
// 	USaveGameConquest* SaveGameInstance = Cast<USaveGameConquest>(UGameplayStatics::CreateSaveGameObject(USaveGameConquest::StaticClass()));
// 	if (!GameInstance)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("0=============================\n USaveGameConquest::SaveHexMap : No GameInstance\n0=================================="));
// 		return ;
// 	}
// 	if (!SaveGameInstance)
// 	{
// 		UE_LOG(LogTemp, Error, TEXT("0=============================\n USaveGameConquest::SaveHexMap : No SaveGameInstance\n0=================================="));
// 		return ;
// 	}
// 	SaveGameInstance->PlayerPawns = GameInstance->HexMap->PlayerPawns;
// 	SaveGameInstance->Map = GameInstance->HexMap->Map;
// 	UGameplayStatics::SaveGameToSlot(SaveGameInstance, TEXT("Default"), 0);	
// }
