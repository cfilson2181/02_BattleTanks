// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Core/Public/Math/UnrealMathUtility.h"

#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward movment, +1 is max upward movement
	void Elevate(float RelativeSpeed);
	
private:
	// Kinematic boundaries
	UPROPERTY(EditAnywhere)
		float MaxDegressPerSecond = 5; 

	UPROPERTY(EditAnywhere)
		float MaxElevationDegrees = 40; // TODO set

	UPROPERTY(EditAnywhere)
		float MinElevationDegrees = 0; //TODO set

};
