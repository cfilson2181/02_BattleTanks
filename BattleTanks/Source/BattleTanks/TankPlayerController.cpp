// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	// Get the controlled tank pawn. Log the controller name if it exists at begin play
	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Controller possessing %s"), *GetControlledTank()->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player controller not possessing tank"));
	}
}

// Run player controller cyclically
void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardCrosshair();
}

// Get the controlled pawn for the tank
ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

// Move the barrel of the tank to point where the crosshairs are pointing
void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return; }
	
	// Get world location through crosshair
	// if it hits the landscape
		// tell the controlled tank to aim at this point
}

