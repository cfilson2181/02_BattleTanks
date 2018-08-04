// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, +1 is max upward speed
	void Rotate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere)
		float MaxDegreesPerSecond = 20.f; // sensible default

	UPROPERTY(EditAnywhere)
		float MaxRotation = 179.f;

	UPROPERTY(EditAnywhere)
		float MinRotation = -179.f;
};