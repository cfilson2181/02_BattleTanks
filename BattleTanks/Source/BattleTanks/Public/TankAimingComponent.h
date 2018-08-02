// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;	//forward declaration to TankBarrel class


// Holds barrel properties and parameters
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Aim the tank barrel at a hit location from the tank controller
	void AimAt(FVector HitLocation, float LaunchSpeed);

public:	
	// set the barrel reference point
	void SetBarrelReference(UTankBarrel* BarrelToSet);
		
private:
	UTankBarrel * Barrel = nullptr;
	
	void MoveBarrelTowards(FVector AimDirection);
};
