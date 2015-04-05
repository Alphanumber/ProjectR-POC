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
	Character.CharacterComponentStruct.CapsuleComponent = DuplicateObject(CapsuleComponent, NULL);
	Character.CharacterComponentStruct.CapsuleHalfHeight = GetCapsuleComponent()->GetUnscaledCapsuleHalfHeight();
	Character.CharacterComponentStruct.SkeletalMesh = GetMesh()->SkeletalMesh;
	Character.CharacterComponentStruct.AnimBlueprintClass = GetMesh()->AnimBlueprintGeneratedClass;
	Character.CharacterComponentStruct.RelativeLocation = GetMesh()->RelativeLocation;

	StartingBattleLocation = GetActorLocation();

	BattleCharacterState = EBattleCharacterState::Idle;

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
	CharacterStruct.CharacterComponentStruct.CapsuleComponent = GetCapsuleComponent();
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

	GetCapsuleComponent()->SetCapsuleHalfHeight(CharacterStruct.CharacterComponentStruct.CapsuleComponent->GetUnscaledCapsuleHalfHeight());
	GetCapsuleComponent()->SetCapsuleRadius(CharacterStruct.CharacterComponentStruct.CapsuleComponent->GetUnscaledCapsuleRadius());
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

void AProjectRCharacter::ChangeHitpoints(int32 DeltaHitpoints)
{
	Character.HitPoints += DeltaHitpoints;
	if (DeltaHitpoints <= 0)
	{
		this->HitpointsReducedEvent(abs(DeltaHitpoints));
	}
}

int32 AProjectRCharacter::GetHitpoints()
{
	return Character.HitPoints;
}

int32 AProjectRCharacter::GetAttackPower()
{
	return Character.AttackPower;
}

void AProjectRCharacter::AdvanceDialogueQueue()
{
	DialogueStruct.DialogueIndex++;
}

void AProjectRCharacter::ResetDialogueQueue()
{
	DialogueStruct.DialogueIndex = 0;
}

bool AProjectRCharacter::isDialogueOver()
{
	if (DialogueStruct.DialogueIndex < DialogueStruct.DialogueQueue.Num())
	{
		return false;
	}
	return true;
}