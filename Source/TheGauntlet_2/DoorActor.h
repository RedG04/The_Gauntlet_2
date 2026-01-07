#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DoorActor.generated.h"

UCLASS()
class THEGAUNTLET_2_API ADoorActor : public AActor
{
	GENERATED_BODY()

public:
	void OpenDoor();

protected:
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* DoorMesh;

	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.f;
};
