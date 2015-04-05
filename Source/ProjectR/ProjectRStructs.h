#pragma once
#include "GameFramework/Character.h"
#include "ProjectRStructs.generated.h"

USTRUCT(BlueprintType)
struct FCharacterComponentStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
		UCapsuleComponent* CapsuleComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
		USkeletalMesh* SkeletalMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
		UAnimBlueprintGeneratedClass* AnimBlueprintClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
		UAnimInstance* AnimInstance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
		float CapsuleHalfHeight;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
		FVector RelativeLocation;

	FCharacterComponentStruct()
	{
		CapsuleComponent = NULL;
		SkeletalMesh = NULL;
		AnimBlueprintClass = NULL;
		AnimInstance = NULL;
		CapsuleHalfHeight = 0.f;
		RelativeLocation = FVector(0.f);
	}
};

USTRUCT(BlueprintType)
struct FCharacterStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStruct)
	struct FCharacterComponentStruct CharacterComponentStruct;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	FString CharacterName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	int32 HitPoints;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	int32 AttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	int32 MagicPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	float AtbSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterStats)
	float AtbProgress;

	FCharacterStruct()
	{
		HitPoints = 100;
		AttackPower = 1;
		MagicPower = 1;
		AtbSpeed = 1.f;
		AtbProgress = 0.f;
		CharacterComponentStruct = FCharacterComponentStruct::FCharacterComponentStruct();
	}
};

USTRUCT(BlueprintType)
struct FDialogueStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
	TArray<FString> DialogueQueue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Dialogue)
	int32 DialogueIndex;

	FDialogueStruct()
	{
		DialogueIndex = 0;
	}
};