#pragma once

#include "LeverActionType.generated.h"

UENUM(BlueprintType)
enum class ELeverActionType : uint8
{
	None        UMETA(DisplayName="None"),
	OpenDoor   UMETA(DisplayName="Open Door"),
	DisableTurret UMETA(DisplayName="Disable Turret"),
	ActivatePlatforms UMETA(DisplayName="Activate Platforms")
};
