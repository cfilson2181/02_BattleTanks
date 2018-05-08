// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed)
{
	// Move the barrel the calculated difference between frames
	// do this given a max elevation speed, and the frame time
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	auto ElevationChange = RelativeSpeed * MaxDegressPerSecond * GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Pitch + ElevationChange;

	//  Restrict the value of the new elevation to minimum and maximum values determined by blueprint editor
	auto Elevation = FMath::Clamp<float>(RawNewElevation, MinElevationDegrees, MaxElevationDegrees);

	// Set the new elevation rotation of the tank barrel
	SetRelativeRotation(FRotator(Elevation, 0, 0));
}


