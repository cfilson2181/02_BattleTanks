// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"


void UTankTurret::RotateTurret(float RelativeSpeed)
{
	// Clamp relative speed to 100% rotation speed in either direction
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	// Get the change in azimuth
	auto AzimuthChange = RelativeSpeed * MaxDegressPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewAzimuth = RelativeRotation.Yaw + AzimuthChange;

	//  Restrict the value of the new elevation to minimum and maximum values determined by blueprint editor
	//auto Azimuth = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	// Set the new elevation rotation of the tank barrel
	SetRelativeRotation(FRotator(0, RawNewAzimuth, 0));
}

