// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantProyectil2.h"
#include "PVZ_USFX_LAB02Projectile.h"

APlantProyectil2::APlantProyectil2()
{
    // Personaliza las propiedades específicas del Tipo 2 aquí
    ShootDamage = 30.0f;
    ShootSpeed = 2000.0f;
}

void APlantProyectil2::Shoot(FVector FireDirection)
{
    // Implementa la lógica de disparo específica del Tipo 2
    if (bCanFire)
    {
        // Dispara un proyectil del Tipo 2 en la dirección especificada
        const FRotator FireRotation = FireDirection.Rotation();
        const FVector SpawnLocation = GetActorLocation() + FireRotation.RotateVector(GunOffset);

        UWorld* const World = GetWorld();
        if (World != nullptr)
        {
            World->SpawnActor<APVZ_USFX_LAB02Projectile>(SpawnLocation, FireRotation);
        }

        bCanFire = false;
        World->GetTimerManager().SetTimer(TimerHandle_ShotTimerExpired, this, &APlant::ShotTimerExpired, FireRate);
    }
}
