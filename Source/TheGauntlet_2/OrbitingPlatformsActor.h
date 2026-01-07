#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OrbitingPlatformsActor.generated.h"

UCLASS()
class THEGAUNTLET_2_API AOrbitingPlatformsActor : public AActor
{
	GENERATED_BODY()

public:
	AOrbitingPlatformsActor();

	virtual void Tick(float DeltaTime) override;

	void ActivateOrbit();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category="Orbit")
	float RotationSpeed = 45.f;

	UPROPERTY(EditAnywhere, Category="Orbit")
	TArray<USceneComponent*> Platforms;

	bool bIsActive = false;
};
