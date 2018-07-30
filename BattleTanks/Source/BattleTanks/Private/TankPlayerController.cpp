// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

/// INIT ROUTINE
void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();	//Make sure the BeginPlay method is called normally above in the hierarchy

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Player controller is not possessing the tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled Tank: %s"), *(ControlledTank->GetName()));
	}
}

/// CYCLIC ROUTINE
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Aim towards crosshair
	AimTowardsCrosshair();
}

/// Get the player controlled tank
ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

/// Aim towards what the crosshair is pointing at
void ATankPlayerController::AimTowardsCrosshair()
{
	// DO NOT RUN IF THERE IS NO CONTROLLED TANK
	if (!GetControlledTank()) { return; }

	// Ray cast to find hit location based on crosshair location
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetControlledTank()->AimAt(HitLocation);
	}

	return;
}

/// Get the location the crosshair is pointing at
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation)
{
	// Find where the crosshair is
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	FVector2D ScreenLocation = FVector2D(CrosshairXLocation * ViewportSizeX, CrosshairYLocation * ViewportSizeY);

	// deproject from the screen
	FVector LookDirection, LookLocation;

	// If we successfully get deprojection information, try to get the look hit location
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, LookLocation, LookDirection))
	{
		// If we hit something, log the information
		FHitResult HitResult;
		if (GetWorld()->LineTraceSingleByChannel(HitResult, LookLocation, LookLocation + LookDirection * LineTraceRange, ECollisionChannel::ECC_Visibility))
		{
			OutHitLocation = HitResult.Location;
			return true;
		}
		//if (GetLookVectorHitLocation(LookLocation, LookDirection, HitResult))
		//{
		//	OutHitLocation = HitResult.Location;
		//	return true;
		//}
	}

	OutHitLocation = FVector(0);
	return false;
}

/// Get the unit vector of the player camera  view
bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookLocation, FVector& LookDirection) const
{
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		LookLocation,
		LookDirection
	);
}

/// Ray cast out from crosshair and see if you hit anything
bool ATankPlayerController::GetLookVectorHitLocation(FVector LookLocation, FVector LookDirection, FHitResult& HitResult) const
{
	return GetWorld()->LineTraceSingleByChannel(
		HitResult,
		LookLocation,
		LookLocation + LookDirection * LineTraceRange,
		ECollisionChannel::ECC_Visibility
	);
}