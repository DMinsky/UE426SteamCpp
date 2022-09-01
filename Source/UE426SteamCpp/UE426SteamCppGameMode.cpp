// Copyright Epic Games, Inc. All Rights Reserved.

#include "UE426SteamCppGameMode.h"
#include "UE426SteamCppCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUE426SteamCppGameMode::AUE426SteamCppGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
