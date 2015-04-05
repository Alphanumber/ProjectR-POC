// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "EncounterVolume.h"
#include "ProjectRStructs.h"
#include "ProjectREnums.h"
#include "ProjectRCharacter.generated.h"

class AProjectRCharacter;

UCLASS(config=Game)
class AProjectRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AProjectRCharacter(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
	bool bIsInBattle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	FCharacterStruct Character;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Encounter)
	AEncounterVolume* EncounterVolume;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Battle)
	FString QueuedCommand;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Battle)
	AProjectRCharacter* TargetCharacter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Battle)
	FVector StartingBattleLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Battle)
	EBattleCharacterState BattleCharacterState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Exploration)
	EExplorationCharacterState ExplorationCharacterState;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Exploration)
	TArray<FString> DialogueQueue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Exploration)
	FDialogueStruct DialogueStruct;

	UFUNCTION(BlueprintNativeEvent, Category = "Initialize")
	void BeginPlay();

	UFUNCTION(BlueprintCallable, Category = "Game")
	virtual void Tick(float DeltaSeconds) OVERRIDE;

	UFUNCTION(BlueprintCallable, Category = Character)
	void MakeCharacterStruct(UPARAM(ref) FCharacterStruct& CharacterStruct);

	UFUNCTION(BlueprintCallable, Category = Character)
	void InitializeCharacter(UPARAM(ref) FCharacterStruct& CharacterStruct);

	UFUNCTION(BlueprintCallable, Category = Character)
	void SetATBProgress(float AtbProgress);

	UFUNCTION(BlueprintCallable, Category = Character)
	float GetATBProgress();

	UFUNCTION(BlueprintCallable, Category = Battle)
	void ChangeHitpoints(int32 DeltaHitpoints);

	UFUNCTION(BlueprintImplementableEvent, Category = Battle)
	virtual void HitpointsReducedEvent(int32 Hitpoints);

	UFUNCTION(BlueprintCallable, Category = Battle)
	int32 GetHitpoints();

	UFUNCTION(BlueprintCallable, Category = Battle)
	int32 GetAttackPower();

	UFUNCTION(BlueprintCallable, Category = Battle)
	void AdvanceDialogueQueue();

	UFUNCTION(BlueprintCallable, Category = Battle)
	void ResetDialogueQueue();

	UFUNCTION(BlueprintCallable, Category = Battle)
	bool isDialogueOver();
};