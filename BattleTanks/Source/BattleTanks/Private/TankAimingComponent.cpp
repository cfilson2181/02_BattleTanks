// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

}

/// Controls where the tank is aiming
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	// Pointer protection! Skip if there is no barrel
	if (!Barrel) { return; }

	// Launch velocity
	FVector OutLaunchVelocity;

	// Starting location of the barrel
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Calculate the OUT launch velocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);
	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrel(AimDirection);
	}
}
/// Setting the barrel reference mesh
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}


/// Move the barrel in a position where the projectile can be launched and reach the target
void UTankAimingComponent::MoveBarrel(FVector AimDirection)
{
	// Work out difference between current barrel rotation and aim direction
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(5); //TODO remove magic number
	
}