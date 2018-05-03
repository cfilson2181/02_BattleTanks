// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	// Get ai controller pawn and report name to log if it exists
	auto AIController = GetAIController();
	if (AIController)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller possesses %s"), *AIController->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("AI controller not found"));
	}

	// Get plaer controlled pawn and report name to log if it exists
	auto PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player tank is %s"), *PlayerTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player tank is not preset"));
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	// Run tank AI cyclic task
	Super::Tick(DeltaTime);

}

// Method to find AI controller pawn and return it as type ATank
ATank* ATankAIController::GetAIController() const
{
	return Cast<ATank>(GetPawn());
}

// Method to get the player controlled tank in level and return pawn as type ATank
ATank* ATankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}