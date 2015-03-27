// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#include "ProjectR.h"
#include "ProjectRCharacter.h"

//////////////////////////////////////////////////////////////////////////
// AProjectRCharacter

AProjectRCharacter::AProjectRCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{

}

void AProjectRCharacter::BeginPlay_Implementation()
{
	character.characterComponentStruct.capsuleHalfHeight = GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	character.characterComponentStruct.sklMesh = GetMesh()->SkeletalMesh;
	character.characterComponentStruct.animBlueprintClass = GetMesh()->AnimBlueprintGeneratedClass;
	character.characterComponentStruct.relativeLocation = GetMesh()->RelativeLocation;

	Super::BeginPlay();
}

void AProjectRCharacter::Tick(float DeltaSeconds){
	if (isInBattle)
	{
		if (character.atbProgress < 1.0f)
		{
			character.atbProgress = character.atbProgress + (character.atbSpeed * (.5 * DeltaSeconds));
		}
		else
		{
			character.atbProgress = 1.0f;
		}
	}

	Super::Tick(DeltaSeconds);
}

void AProjectRCharacter::MakeCharacterStruct(UPARAM(ref) FCharacterStruct& characterStruct)
{
	characterStruct.characterComponentStruct.capsuleHalfHeight = GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	characterStruct.characterComponentStruct.sklMesh = GetMesh()->SkeletalMesh;
	characterStruct.characterComponentStruct.animBlueprintClass = GetMesh()->AnimBlueprintGeneratedClass;
	characterStruct.characterComponentStruct.relativeLocation = GetMesh()->RelativeLocation;
}

void AProjectRCharacter::InitCharacter(UPARAM(ref) FCharacterStruct& characterStruct)
{
	character.attackPower = characterStruct.attackPower;
	character.characterName = characterStruct.characterName;
	character.hitPoints = characterStruct.hitPoints;
	character.magicPower = characterStruct.magicPower;

	GetCapsuleComponent()->SetCapsuleHalfHeight(characterStruct.characterComponentStruct.capsuleHalfHeight);
	GetMesh()->SetSkeletalMesh(characterStruct.characterComponentStruct.sklMesh);
	GetMesh()->AnimBlueprintGeneratedClass = characterStruct.characterComponentStruct.animBlueprintClass;
	GetMesh()->InitAnim(true);
	GetMesh()->SetRelativeLocation(characterStruct.characterComponentStruct.relativeLocation);
}

void AProjectRCharacter::SetATBProgress(float atbProgress)
{
	character.atbProgress = atbProgress;
}

float AProjectRCharacter::GetATBProgress()
{
	return character.atbProgress;
}