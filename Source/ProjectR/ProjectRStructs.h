#pragma once
#include "GameFramework/Character.h"
#include "ProjectRStructs.generated.h"

USTRUCT(BlueprintType)
struct FCharacterComponentStruct
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

	FCharacterComponentStruct()
	{
		sklMesh = NULL;
		animBlueprintClass = NULL;
		animInstance = NULL;
		capsuleHalfHeight = 0.f;
		relativeLocation = FVector(0.f);
	}
};

USTRUCT(BlueprintType)
struct FCharacterStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
	struct FCharacterComponentStruct characterComponentStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	FString characterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	int32 hitPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	int32 attackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	int32 magicPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	float atbSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	float atbProgress;

	FCharacterStruct()
	{
		hitPoints = 100;
		attackPower = 1;
		magicPower = 1;
		atbSpeed = 1.f;
		atbProgress = 0.f;
		characterComponentStruct = FCharacterComponentStruct::FCharacterComponentStruct();
	}
};