// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	// No need to protect the aiming component
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("AimingComponent"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Aim at a player
void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}


/// Set barrel reference
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	
	// Keep local reference to barrel
	Barrel = BarrelToSet;
}

/// Set tank turret reference
void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

/// Fire projectile
void ATank::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("FIRE!!!"));
	
	// If there is no barrel instantiated, skip the rest of the code
	if (!Barrel) { return; }

	// Spawn a projectile in the game
	auto ProjectileSpawnParameters = FActorSpawnParameters();
	auto Projectile = GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint, 
		Barrel->GetSocketLocation(FName("Projectile")),
		Barrel->GetSocketRotation(FName("Projectile"))
		);

	Projectile->LaunchProjectile(LaunchSpeed);

	return;
}