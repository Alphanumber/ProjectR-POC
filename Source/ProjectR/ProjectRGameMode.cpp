// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ProjectR.h"
#include "ProjectRGameMode.h"
#include "ProjectRCharacter.h"

AProjectRGameMode::AProjectRGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/ThirdPersonCharacter"));
	//if (PlayerPawnBPClass.Class != NULL)
	//{
	//	DefaultPawnClass = PlayerPawnBPClass.Class;
	//}
	DefaultPawnClass = NULL;
}
