// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "TankAimingComponent.generated.h"

class UTankBarrel; //Forward declaration - allows you to reference this class without creating a chain of dependency
class UTankTurret; //Forward declaration 

/// Holds Barrel's properties and Elevate method
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	// Creates a barrel reference that can be obtained in the blueprint constructor
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// Creates a turret reference that can be obtained in the blueprint constructor
	void SetTurretReference(UTankTurret* TurretToSet);

	// Aim the tank barrel
	void AimAt(FVector WorldSpaceAim, float LaunchSpeed);

	// Move the tank barrel at the direction that should be aimed
	void MoveBarrel(FVector AimDirection);

private:
	UTankBarrel* Barrel = nullptr;
	UTankTurret* Turret = nullptr;
};
