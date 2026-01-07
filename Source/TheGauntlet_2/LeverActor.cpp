#include "LeverActor.h"
#include "Interactable.h"

void ALeverActor::Interact_Implementation(AActor* Interactor)
{
	if (bHasBeenInteracted)
		return;

	Super::Interact_Implementation(Interactor);

	SetColor(FLinearColor::Green);

	if (!TargetActor)
		return;
	
	if (TargetActor->Implements<UInteractable>())
	{
		IInteractable::Execute_Interact(TargetActor, this);
	}
}
