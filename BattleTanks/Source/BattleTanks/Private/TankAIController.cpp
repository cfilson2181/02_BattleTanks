// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	// Get ai controller pawn and report name to log if it exists
	auto AIController = GetAIController();

	// Get plaer controlled pawn and report name to log if it exists
	auto PlayerTank = GetPlayerTank();
}

void ATankAIController::Tick(float DeltaTime)
{
	// Run tank AI cyclic task
	Super::Tick(DeltaTime);

	if (GetPlayerTank())
	{
		// TODO: move towards the player

		// Aim towards the player
		GetAIController()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire if ready
	}
}

/// Method to find AI controller pawn and return it as type ATank
ATank* ATankAIController::GetAIController() const
{
	return Cast<ATank>(GetPawn());
}

/// Method to get the player controlled tank in level and return pawn as type ATank
ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

