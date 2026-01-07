#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

AProjectile::AProjectile()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->InitialSpeed = 1200.f;
	Movement->MaxSpeed = 1200.f;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	DeactivateProjectile();
}

void AProjectile::ActivateProjectile(const FVector& StartLocation, const FVector& Direction)
{
	SetActorLocation(StartLocation);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	Movement->Velocity = Direction * Movement->InitialSpeed;

	bIsActive = true;
}

void AProjectile::DeactivateProjectile()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);

	Movement->StopMovementImmediately();

	bIsActive = false;
}
