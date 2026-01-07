#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"
#include "InteractableBase.generated.h"

UCLASS(Abstract)
class THEGAUNTLET_2_API AInteractableBase : public AActor, public IInteractable
{
	GENERATED_BODY()

public:
	AInteractableBase();

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	// Dynamic material
	UPROPERTY()
	UMaterialInstanceDynamic* DynamicMaterial;

	virtual void BeginPlay() override;
	
	void SetColor(const FLinearColor& NewColor);

	// Base state
	bool bHasBeenInteracted = false;

public:
	virtual void Interact_Implementation(AActor* Interactor) override;
};
