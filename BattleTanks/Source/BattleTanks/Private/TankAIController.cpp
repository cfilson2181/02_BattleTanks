// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

/// INIT ROUTINE for AI tank
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControllerTank = GetAIController();
	auto PlayerTank = GetPlayerTank();

	if (!AIControllerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller not possessing tank"));
		return;
	}

	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("Player Controller is missing"));
		return;
	}

	UE_LOG(LogTemp, Warning, TEXT("AI Controller %s has found player %s"), *(AIControllerTank->GetName()), *(PlayerTank->GetName()));
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!GetAIController()) { return; }
	
	if (GetPlayerTank())
	{
		// TODO: Move towards player

		// Aim towards player
		GetAIController()->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire!
	}
}

/// Get the tank owned by the ai controller
ATank* ATankAIController::GetAIController() const
{
	return Cast<ATank>(GetPawn());
}

/// Get the player controlled tank
ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();

	// DO NOT RUN IF THERE IS NO PLAYER CONTROLLER
	if (!PlayerPawn) { return nullptr; }

	return Cast<ATank>(PlayerPawn);
}


