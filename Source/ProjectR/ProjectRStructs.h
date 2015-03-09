#pragma once
#include "GameFramework/Character.h"
#include "ProjectRStructs.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
	USkeletalMesh* sklMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
	UAnimBlueprintGeneratedClass* animBlueprintClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
	UAnimInstance* animInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
	float capsuleHalfHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
	FVector relativeLocation;

	FCharacterStruct()
	{
		sklMesh = NULL;
		animBlueprintClass = NULL;
		animInstance = NULL;
		capsuleHalfHeight = 0.f;

		relativeLocation = FVector(0.f);
	}
};