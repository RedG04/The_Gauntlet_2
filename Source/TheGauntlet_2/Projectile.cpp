#include "Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"

AProjectile::AProjectile()
{
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	Mesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	Mesh->SetCollisionProfileName(TEXT("BlockAll"));
	Mesh->SetNotifyRigidBodyCollision(true);
	Mesh->SetGenerateOverlapEvents(true);
	
	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->InitialSpeed = 1200.f;
	Movement->MaxSpeed = 1200.f;
}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	Mesh->OnComponentHit.AddDynamic(this, &AProjectile::OnProjectileHit);
	
	DeactivateProjectile();
}

void AProjectile::ActivateProjectile(const FVector& StartLocation, const FVector& Direction)
{
	SetActorLocation(StartLocation);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
	
	Movement->StopMovementImmediately();

	Movement->Velocity = Direction.GetSafeNormal() * Movement->InitialSpeed;

	bIsActive = true;
}


void AProjectile::DeactivateProjectile()
{
	SetActorHiddenInGame(true);
	SetActorEnableCollision(false);
	
	Movement->StopMovementImmediately();

	bIsActive = false;
}


void AProjectile::OnProjectileHit(
	UPrimitiveComponent* HitComponent,
	AActor* OtherActor,
	UPrimitiveComponent* OtherComp,
	FVector NormalImpulse,
	const FHitResult& Hit)
{
	if (!bIsActive)
		return;

	DeactivateProjectile();
}