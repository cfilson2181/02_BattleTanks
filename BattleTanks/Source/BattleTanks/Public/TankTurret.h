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
	void RotateTurret(float RelativeSpeed);
	
private:
	// Kinematic boundaries
	UPROPERTY(EditAnywhere)
		float MaxDegressPerSecond = 25;
	
};
