#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "TurretActor.generated.h"

class AProjectile;

UCLASS()
class THEGAUNTLET_2_API ATurretActor : public AInteractableBase
{
	GENERATED_BODY()

public:
	ATurretActor();

	virtual void BeginPlay() override;
	virtual void Interact_Implementation(AActor* Interactor) override;

protected:
	// Pool
	UPROPERTY(EditDefaultsOnly, Category="Turret|Pool")
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditDefaultsOnly, Category="Turret|Pool")
	int32 PoolSize = 20;

	UPROPERTY()
	TArray<AProjectile*> ProjectilePool;

	// Fire
	UPROPERTY(EditDefaultsOnly, Category="Turret|Fire")
	float FireRate = 1.0f;

	FTimerHandle FireTimer;
	FTimerHandle DisableTimer;

	bool bIsActive = true;

	// Disable
	UPROPERTY(EditDefaultsOnly, Category="Turret|Disable")
	float DisableTime = 5.f;

	void Fire();
	AProjectile* GetFreeProjectile();

	void SetTurretActive(bool bNewState);
	void PrintDebug();
	void ReactivateTurret();

};
