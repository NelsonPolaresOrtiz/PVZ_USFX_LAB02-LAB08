// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantProyectil1.h"
#include "PVZ_USFX_LAB02Projectile.h"

APlantProyectil1::APlantProyectil1()
{
    // Personaliza las propiedades específicas del Tipo 1 aquí
    ShootDamage = 20.0f;
    ShootSpeed = 1500.0f;
}

void APlantProyectil1::Shoot(FVector FireDirection)
{
    // Implementa la lógica de disparo específica del Tipo 1
    if (bCanFire)
    {
        // Dispara un proyectil del Tipo 1 en la dirección especificada
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
