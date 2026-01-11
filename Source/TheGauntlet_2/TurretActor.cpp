#include "TurretActor.h"
#include "Projectile.h"
#include "Engine/World.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

ATurretActor::ATurretActor()
{
    PrimaryActorTick.bCanEverTick = false;
}

void ATurretActor::BeginPlay()
{
    Super::BeginPlay();

    if (!ProjectileClass)
    {
        UE_LOG(LogTemp, Error, TEXT("ProjectileClass NON impostata su %s"), *GetName());
        return;
    }

    for (int32 i = 0; i < PoolSize; i++)
    {
        AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass);
        if (Projectile)
        {
            Projectile->DeactivateProjectile();
            ProjectilePool.Add(Projectile);
        }
    }

    SetTurretActive(true);
}


void ATurretActor::Fire()
{
    if (!bIsActive)
        return;

    AProjectile* Projectile = GetFreeProjectile();
    if (!Projectile)
        return;

    FVector MuzzleLocation = GetActorLocation() + GetActorForwardVector() * 100.f;
    Projectile->ActivateProjectile(MuzzleLocation, GetActorForwardVector());

    PrintDebug();
}

AProjectile* ATurretActor::GetFreeProjectile()
{
    for (AProjectile* Projectile : ProjectilePool)
    {
        if (Projectile && !Projectile->IsActive())
            return Projectile;
    }
    return nullptr;
}

void ATurretActor::SetTurretActive(bool bNewState)
{
    bIsActive = bNewState;

    if (bIsActive)
    {
        SetColor(FLinearColor(1.f, 0.5f, 0.f));
        GetWorldTimerManager().SetTimer(FireTimer, this, &ATurretActor::Fire, FireRate, true);
    }
    else
    {
        SetColor(FLinearColor::Blue); // Blue
        GetWorldTimerManager().ClearTimer(FireTimer);
    }
}

void ATurretActor::Interact_Implementation(AActor* Interactor)
{
    SetTurretActive(false);

    GetWorldTimerManager().SetTimer(
        DisableTimer,
        this,
        &ATurretActor::ReactivateTurret,
        DisableTime,
        false
    );
}

void ATurretActor::ReactivateTurret()
{
    SetTurretActive(true);
}


void ATurretActor::PrintDebug()
{
    int32 ActiveCount = 0;
    for (AProjectile* P : ProjectilePool)
    {
        if (P && P->IsActive())
            ActiveCount++;
    }

    GEngine->AddOnScreenDebugMessage(
        -1, 1.f, FColor::Yellow,
        FString::Printf(TEXT("Pool Size: %d | Active: %d"), PoolSize, ActiveCount)
    );
}
