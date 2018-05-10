// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	// Get the controlled tank pawn. Log the controller name if it exists at begin play
	auto ControlledTank = GetControlledTank();
}

// Run player controller cyclically
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

/// Get the controlled pawn for the tank
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

/// Move the barrel of the tank to point where the crosshairs are pointing
void ATankPlayerController::AimTowardCrosshair()
{
	// Protect against uninitialized pointer
	if (!GetControlledTank()) { return; }
	
	// Out parameter
	FVector HitLocation; 

	// If you are hitting something with crosshairs, 
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}
}

/// Get the sightline of the crosshair on the screen and find objects for the tank to aim at
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	// Get the location of the UI crosshair in pixels
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	// "De-project" the screen position of the crosshair to a world direction
	FVector LookDirection, WorldLocation;
	if (GetLookDirection(ScreenLocation, LookDirection, WorldLocation))
	{
		// Line-trace along that look direction, and see what we hit (up to max range) out from the reticle and look for the first thing that is hit
		GetLookVectorHitLocation(OutHitLocation, LookDirection, WorldLocation);
	}

	return true;
}

/// Get the look direction (absolute) in the world of the crosshair
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection, FVector& WorldLocation) const
{
	// placeholder variable
	//FVector WorldLocation;

	// "Deproject" the screen position of the crosshair in the world
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		WorldLocation,
		LookDirection
	);
}


bool ATankPlayerController::GetLookVectorHitLocation(FVector& HitLocation, FVector LookDirection, FVector WorldLocation) const
{
	// create hit result placeholder
	FHitResult HitResult;
	//auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = WorldLocation + (LookDirection * LineTraceRange);
	
	// If there is an object hit, then it returns true and updates the location of the hit object
	if (GetWorld()->LineTraceSingleByChannel(
		HitResult,
		WorldLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{
		//DrawDebugLine(
		//	GetWorld(),
		//	WorldLocation,
		//	EndLocation,
		//	FColor(255,0,0),
		//	false, -1, 0,
		//	12.333
		//	);
		HitLocation = HitResult.Location;
		return true;
	}

	// Otherwise, set vector to 0
	HitLocation = FVector(0.f);
	return false;
}