// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

/// INIT ROUTINE for AI tank
void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	AIControllerTank = Cast<ATank>(GetPawn());
	PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());

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

	if (!AIControllerTank) { return; }
	
	if (PlayerTank)
	{
		// TODO: Move towards player

		// Aim towards player
		AIControllerTank->AimAt(PlayerTank->GetActorLocation());

		// Fire every frame
		AIControllerTank->Fire();
	}
}


