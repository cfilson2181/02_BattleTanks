// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);
	
private:
	// Kinematic boundaries
	UPROPERTY(EditAnywhere)
		float MaxDegressPerSecond = 20; 

	UPROPERTY(EditAnywhere)
		float MaxElevationDegrees = 40; // TODO set

	UPROPERTY(EditAnywhere)
		float MinElevationDegrees = 0; //TODO set

};
