#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "ArtifactActor.generated.h"

UCLASS()
class THEGAUNTLET_2_API AArtifactActor : public AInteractableBase
{
	GENERATED_BODY()

public:
	virtual void Interact_Implementation(AActor* Interactor) override;
};
