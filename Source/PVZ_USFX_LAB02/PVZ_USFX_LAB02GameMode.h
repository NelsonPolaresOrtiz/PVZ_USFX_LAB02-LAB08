// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PVZ_USFX_LAB02GameMode.generated.h"

UCLASS(MinimalAPI)
class APVZ_USFX_LAB02GameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	APVZ_USFX_LAB02GameMode();

	TArray<class AZombie*> ArrayZombies;
	TArray<class APlant*> ArrayPlants;

	int32 NumberZombies = 10;
	int32 NumberZombiesSpawned = 0;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	virtual void BeginPlay() override;
	AZombie* SpawnZombie(FVector _spawnPosition);
	APlant* SpawnPlant(FVector _spawnPosition);

};



