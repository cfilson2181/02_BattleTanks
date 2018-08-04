// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankBarrel.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	//No need to protect pointers because it is added in the constructor (will always fail)
	TankAimingComponent = CreateDefaultSubobject<UTankAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

// Aim the tank barrel at the hit location
void ATank::AimAt(FVector HitLocation)
{
	TankAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

// Set the barrel reference object
void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimingComponent->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

// Set the turret reference object
void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimingComponent->SetTurretReference(TurretToSet);
}

// Fire a projectile
void ATank::Fire()
{
	// Protect against a barrel reference that does not exist
	if (!Barrel) { return; }

	//// Determine if the tank has reloaded a new projectile since the last fire time
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (isReloaded)
	{
		// spawn the projectile in the world for launching
		auto Projectile = GetWorld()->SpawnActor<AProjectile>(
											ProjectileBlueprint,
											Barrel->GetSocketLocation(FName("Projectile")),
											Barrel->GetSocketRotation(FName("Projectile")));

		//// Launch the projectile at the desired launch speed
		Projectile->LaunchProjectile(LaunchSpeed);
			
		//// Update time of last launch to this frame
		LastFireTime = FPlatformTime::Seconds();
		UE_LOG(LogTemp, Warning, TEXT("Last fire time: %f"), LastFireTime);
	}
}

