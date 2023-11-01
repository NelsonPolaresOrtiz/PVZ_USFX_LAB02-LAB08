// Fill out your copyright notice in the Description page of Project Settings.


#include "PlantProyectil3.h"
#include "PVZ_USFX_LAB02Projectile.h"

APlantProyectil3::APlantProyectil3()
{
    // Personaliza las propiedades espec�ficas del Tipo 3 aqu�
    ShootDamage = 40.0f;
    ShootSpeed = 2500.0f;
}

void APlantProyectil3::Shoot(FVector FireDirection)
{
    // Implementa la l�gica de disparo espec�fica del Tipo 3
    if (bCanFire)
    {
        // Dispara un proyectil del Tipo 3 en la direcci�n especificada
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


void APlantProyectil3::Shoot(FVector FireDirection)
{
  
}
