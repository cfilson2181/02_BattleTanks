// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "TankAimingComponent.h"

#include "Tank.generated.h"

class UTankBarrel;

UCLASS()
class BATTLETANKS_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	void AimAt(FVector HitLocation);

	// create a blueprint callable class for blueprint scripting the barrel
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetBarrelReference(UTankBarrel* BarrelToSet);

	// Create a blueprint callable class for blueprint scripting the turret
	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret* TurretToSet);

protected:
	UTankAimingComponent* TankAimingComponent = nullptr;

public:	
	// Begin play
	virtual void BeginPlay() override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	// Set firing velocity
	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 100000.f; //sensible starting value of 1000 m/s

	
};
