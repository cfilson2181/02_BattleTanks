// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	// Obtain the controlled tank
	ATank * GetControlledTank() const;

	// Aim the barrel towards the crosshairs
	void AimTowardsCrosshair();

	// Figure out if the crosshair is pointing at something that can be hit
	bool GetSightRayHitLocation(FVector &OutHitLocation);

	// run the init routine for the tank
	void BeginPlay() override;

	// run the cyclic routine for the tank
	void Tick(float DeltaTime) override;
	


public:
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333f;
};
