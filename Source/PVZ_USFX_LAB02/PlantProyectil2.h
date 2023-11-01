// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plant.h"
#include "PlantProyectil2.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API APlantProyectil2 : public APlant
{
	GENERATED_BODY()
public:
    APlantProyectil2();
    float ShootDamage;
    float ShootSpeed;
    // Propiedades espec�ficas del Tipo 2
    UPROPERTY(EditAnywhere)
        float CustomProperty2;

    // Implementa m�todos y propiedades espec�ficos para el Tipo 2
    void  Shoot(FVector FireDirection) override;
};
