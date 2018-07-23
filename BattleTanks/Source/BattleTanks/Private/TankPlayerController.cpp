// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

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

ATank * ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}