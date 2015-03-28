// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProjectRStructs.h"
#include "GameFramework/Volume.h"
#include "EncounterVolume.generated.h"

/**
* Forward declaration of AProjectRCharacter
*/
class AProjectRCharacter;

/**
 * Volume for mapping exploration plane characters to encounters
 */
UCLASS()
class PROJECTR_API AEncounterVolume : public AVolume
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Encounter)
	TArray<FCharacterStruct> MappedCharacterStructs;
};
