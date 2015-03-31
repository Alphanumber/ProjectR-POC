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