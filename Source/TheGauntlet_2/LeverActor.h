#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LeverActor.generated.h"

UCLASS()
class THEGAUNTLET_2_API ALeverActor : public AActor
{
	GENERATED_BODY()

public:
	ALeverActor();

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

	virtual void BeginPlay() override;
};
