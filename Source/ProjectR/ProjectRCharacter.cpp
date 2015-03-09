// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ProjectR.h"
#include "ProjectRCharacter.h"

//////////////////////////////////////////////////////////////////////////
// AProjectRCharacter

AProjectRCharacter::AProjectRCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void AProjectRCharacter::InitCharacter(UPARAM(ref) FCharacterStruct& characterStruct)
{
	GetCapsuleComponent()->SetCapsuleHalfHeight(characterStruct.capsuleHalfHeight);
	GetMesh()->SetSkeletalMesh(characterStruct.sklMesh);
	GetMesh()->AnimBlueprintGeneratedClass = characterStruct.animBlueprintClass;
	GetMesh()->InitAnim(true);
	GetMesh()->SetRelativeLocation(characterStruct.relativeLocation);
}
