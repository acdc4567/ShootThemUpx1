// Copyright Epic Games, Inc. All Rights Reserved.

#include "ShootThemUpGameMode.h"
#include "ShootThemUpCharacter.h"
#include "UObject/ConstructorHelpers.h"

AShootThemUpGameMode::AShootThemUpGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
