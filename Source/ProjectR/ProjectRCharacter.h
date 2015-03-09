// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/Character.h"
#include "ProjectRStructs.h"
#include "ProjectRCharacter.generated.h"

UCLASS(config=Game)
class AProjectRCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AProjectRCharacter(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
	bool isInBattle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
	FCharacterStruct character;

	UFUNCTION(BlueprintCallable, Category = Character)
	void InitCharacter(UPARAM(ref) FCharacterStruct& characterStruct);
};

