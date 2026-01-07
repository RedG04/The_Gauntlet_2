#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "LeverActionType.h"
#include "LeverActor.generated.h"

UCLASS()
class THEGAUNTLET_2_API ALeverActor : public AInteractableBase
{
	GENERATED_BODY()

public:
	virtual void Interact_Implementation(AActor* Interactor) override;

protected:
	UPROPERTY(EditInstanceOnly, Category="Lever")
	ELeverActionType LeverAction = ELeverActionType::None;
	
	UPROPERTY(EditInstanceOnly, Category="Lever")
	AActor* TargetActor;
};
