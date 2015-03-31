// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "ProjectRGameMode.generated.h"

UCLASS(minimalapi)
class AProjectRGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	AProjectRGameMode(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Battle)
	AActor* ActorToFace;
};



