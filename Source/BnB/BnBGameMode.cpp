// Copyright Epic Games, Inc. All Rights Reserved.

#include "BnBGameMode.h"
#include "BnBPlayerController.h"
#include "BnBCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABnBGameMode::ABnBGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABnBPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}