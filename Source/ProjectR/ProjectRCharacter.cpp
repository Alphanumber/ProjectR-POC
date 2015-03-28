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
	Character.CharacterComponentStruct.CapsuleHalfHeight = GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	Character.CharacterComponentStruct.SkeletalMesh = GetMesh()->SkeletalMesh;
	Character.CharacterComponentStruct.AnimBlueprintClass = GetMesh()->AnimBlueprintGeneratedClass;
	Character.CharacterComponentStruct.RelativeLocation = GetMesh()->RelativeLocation;

	if (EncounterVolume != NULL)
	{
		EncounterVolume->MappedCharacterStructs.Add(Character);
	}

	Super::BeginPlay();
}

void AProjectRCharacter::Tick(float DeltaSeconds){
	if (bIsInBattle)
	{
		if (Character.AtbProgress < 1.0f)
		{
			Character.AtbProgress = Character.AtbProgress + (Character.AtbSpeed * (.5 * DeltaSeconds));
		}
		else
		{
			Character.AtbProgress = 1.0f;
		}
	}

	Super::Tick(DeltaSeconds);
}

void AProjectRCharacter::MakeCharacterStruct(UPARAM(ref) FCharacterStruct& CharacterStruct)
{
	CharacterStruct.CharacterComponentStruct.CapsuleHalfHeight = GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	CharacterStruct.CharacterComponentStruct.SkeletalMesh = GetMesh()->SkeletalMesh;
	CharacterStruct.CharacterComponentStruct.AnimBlueprintClass = GetMesh()->AnimBlueprintGeneratedClass;
	CharacterStruct.CharacterComponentStruct.RelativeLocation = GetMesh()->RelativeLocation;
}

void AProjectRCharacter::InitializeCharacter(UPARAM(ref) FCharacterStruct& CharacterStruct)
{
	Character.AttackPower = CharacterStruct.AttackPower;
	Character.CharacterName = CharacterStruct.CharacterName;
	Character.HitPoints = CharacterStruct.HitPoints;
	Character.MagicPower = CharacterStruct.MagicPower;

	GetCapsuleComponent()->SetCapsuleHalfHeight(CharacterStruct.CharacterComponentStruct.CapsuleHalfHeight);
	GetMesh()->SetSkeletalMesh(CharacterStruct.CharacterComponentStruct.SkeletalMesh);
	GetMesh()->AnimBlueprintGeneratedClass = CharacterStruct.CharacterComponentStruct.AnimBlueprintClass;
	GetMesh()->InitAnim(true);
	GetMesh()->SetRelativeLocation(CharacterStruct.CharacterComponentStruct.RelativeLocation);
}

void AProjectRCharacter::SetATBProgress(float AtbProgress)
{
	Character.AtbProgress = AtbProgress;
}

float AProjectRCharacter::GetATBProgress()
{
	return Character.AtbProgress;
}