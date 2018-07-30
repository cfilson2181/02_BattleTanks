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
	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation))
	{

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

	UE_LOG(LogTemp, Warning, TEXT("Crosshair Location is at %s"), *(ScreenLocation.ToString()));
	// deproject from the screen
	// Line trace 

	return true;
}