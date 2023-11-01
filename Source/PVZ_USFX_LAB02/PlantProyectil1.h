// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Plant.h"
#include "PlantProyectil1.generated.h"

/**
 * 
 */
UCLASS()
class PVZ_USFX_LAB02_API APlantProyectil1 : public APlant
{
	GENERATED_BODY()

public:
    APlantProyectil1();
    float ShootDamage;
    float ShootSpeed;
    // Propiedades específicas del Tipo 1
    UPROPERTY(EditAnywhere)
        float CustomProperty1;
    void  Shoot(FVector FireDirection) override;
};
