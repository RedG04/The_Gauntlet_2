#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "ExitActor.generated.h"

UCLASS()
class THEGAUNTLET_2_API AExitActor : public AInteractableBase
{
	GENERATED_BODY()

public:
	virtual void Interact_Implementation(AActor* Interactor) override;

protected:
	UPROPERTY(EditDefaultsOnly, Category="Exit")
	float ReturnToMenuDelay = 3.f;

	void ReturnToMainMenu();
};
