#include "DoorActor.h"

void ADoorActor::OpenDoor()
{
	FRotator NewRotation = DoorMesh->GetRelativeRotation();
	NewRotation.Yaw += OpenAngle;
	DoorMesh->SetRelativeRotation(NewRotation);
}
