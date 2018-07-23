// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank* ATankAIController::GetAIController() const
{
	return Cast<ATank>(GetPawn());
}


void ATankAIController::BeginPlay()
{

	auto AIControllerTank = GetAIController();

	if (!AIControllerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Controller not possessing tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controller: %s"), *(AIControllerTank->GetName()));
	}
}




