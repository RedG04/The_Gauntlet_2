#include "InteractableBase.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/MaterialInstanceDynamic.h"

AInteractableBase::AInteractableBase()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void AInteractableBase::BeginPlay()
{
	Super::BeginPlay();

	DynamicMaterial = Mesh->CreateDynamicMaterialInstance(0);

	if (DynamicMaterial)
	{
		SetColor(FLinearColor::White);
	}
}

void AInteractableBase::SetColor(const FLinearColor& NewColor)
{
	if (DynamicMaterial)
	{
		DynamicMaterial->SetVectorParameterValue("Color", NewColor);
	}
}

void AInteractableBase::Interact_Implementation(AActor* Interactor)
{
	if (bHasBeenInteracted)
		return;

	bHasBeenInteracted = true;
}
