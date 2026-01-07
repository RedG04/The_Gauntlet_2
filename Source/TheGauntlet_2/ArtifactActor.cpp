#include "ArtifactActor.h"
#include "GameFramework/Character.h"
#include "TheGauntlet_2Character.h"


void AArtifactActor::Interact_Implementation(AActor* Interactor)
{
	ATheGauntlet_2Character* Character = Cast<ATheGauntlet_2Character>(Interactor);
	if (!Character)
		return;

	SetColor(FLinearColor::Green);

	Mesh->SetSimulatePhysics(false);

	AttachToComponent(
		Character->GetMesh(),
		FAttachmentTransformRules::SnapToTargetNotIncludingScale,
		"ArtifactSocket"
	);

	Character->SetHasArtifact(true);
}
