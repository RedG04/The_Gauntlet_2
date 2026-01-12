#include "OrbitingPlatformsActor.h"

AOrbitingPlatformsActor::AOrbitingPlatformsActor()
{
	PrimaryActorTick.bCanEverTick = true;

	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);

	Pivot = CreateDefaultSubobject<USceneComponent>("Pivot");
	Pivot->SetupAttachment(Root);
}

void AOrbitingPlatformsActor::BeginPlay()
{
	Super::BeginPlay();
}

void AOrbitingPlatformsActor::ActivateOrbit()
{
	bIsActive = true;
}

void AOrbitingPlatformsActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bIsActive)
		return;

	Pivot->AddLocalRotation(
		FRotator(0.f, RotationSpeed * DeltaTime, 0.f)
	);
}

