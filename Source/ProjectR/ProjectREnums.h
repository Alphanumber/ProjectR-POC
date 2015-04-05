#pragma once

#include "ProjectREnums.generated.h"

UENUM(BlueprintType)
enum class EBattleMenuMode : uint8
{
	Command,
	Target
};

UENUM(BlueprintType)
enum class EBattleCharacterState : uint8
{
	Idle,
	Transition,
	Action
};

UENUM(BlueprintType)
enum class EExplorationCharacterState : uint8
{
	Friendly,
	Hostile
};

UENUM(BlueprintType)
enum class EDialogueState: uint8
{
	Roaming,
	Talking
};