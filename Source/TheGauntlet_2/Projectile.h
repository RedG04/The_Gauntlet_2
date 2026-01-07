#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class THEGAUNTLET_2_API AProjectile : public AActor
{
	GENERATED_BODY()

public:
	AProjectile();

	void ActivateProjectile(const FVector& StartLocation, const FVector& Direction);
	void DeactivateProjectile();

	bool IsActive() const { return bIsActive; }

protected:
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere)
	class UProjectileMovementComponent* Movement;

	bool bIsActive = false;

	virtual void BeginPlay() override;
};
