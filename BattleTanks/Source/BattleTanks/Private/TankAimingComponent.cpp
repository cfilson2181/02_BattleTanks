// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"


// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Aim the tank barrel at a hit location
void UTankAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	// protect against a non-existant barrel reference
	if (!Barrel) { return; }

	FVector OutLaunchVelocity;
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));

	// Calculate the OutLaunchVelocity
	bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity
	(
		this,				// use this object in the world
		OutLaunchVelocity,	// The launch velocity unit vector 
		StartLocation,		// starting location of the projectile
		HitLocation,		// desired landing location of the projectile
		LaunchSpeed,		// velocity magnitude at start of projectile motion
		false,
		0,
		0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	);

	if (bHaveAimSolution)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		MoveBarrelTowards(AimDirection);

		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("%f: Aim solution found"), Time);
	}
	else
	{
		auto Time = GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Error, TEXT("%f: Aim solution NOT found"), Time);
	}
	return;
}

// Set the barrel reference
void UTankAimingComponent::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

// Set the turret reference
void UTankAimingComponent::SetTurretReference(UTankTurret * TurretToSet)
{
	Turret = TurretToSet;
}

// change the barrel rotation
void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	// Find where the barrel is
	// Determine the difference in rotation needed to get the barrel in the right position
	// Determine rotation speed 

	// Calculate the rate of change in barrel speed to move the barrel in the tick to the right position
	auto TargetRotation = Barrel->GetForwardVector().Rotation();
	auto AimAsRotation = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotation - TargetRotation;
	
	// Move the barrel the right amount this frame
	Barrel->Elevate(DeltaRotator.Pitch);	
	Turret->Rotate(DeltaRotator.Yaw);		

	// given a max elevation and the frame time
}