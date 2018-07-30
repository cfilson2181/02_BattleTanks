// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Engine/Classes/Engine/World.h"
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
	
public:
	void BeginPlay() override;

	void Tick(float DeltaTime) override;

private:
	// Obtain the controlled tank
	ATank * GetControlledTank() const;

	// Aim the barrel towards the crosshairs
	void AimTowardsCrosshair();

	// Figure out if the crosshair is pointing at something that can be hit
	bool GetSightRayHitLocation(FVector &OutHitLocation);
	
	// Figure out look direction of player camera
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookLocation, FVector& LookDirection) const;

	// Ray cast method
	bool GetLookVectorHitLocation(FVector LookLocation, FVector LookDirection, FHitResult& HitResult) const;

	// New editable properties for screen location of crosshair
	UPROPERTY(EditAnywhere)
		float CrosshairXLocation = 0.5f;

	UPROPERTY(EditAnywhere)
		float CrosshairYLocation = 0.3333f;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.f;
};
