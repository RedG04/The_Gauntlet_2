#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Interactable.generated.h"

// Parte UObject
UINTERFACE(BlueprintType)
class THEGAUNTLET_2_API UInteractable : public UInterface
{
	GENERATED_BODY()
};

class THEGAUNTLET_2_API IInteractable
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category="Interactable")
	void Interact(AActor* Interactor);
};
