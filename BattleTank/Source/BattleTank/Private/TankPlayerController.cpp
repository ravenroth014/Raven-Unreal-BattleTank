// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	const auto ControlledTank = GetControlledTank();
	if(!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing %s"), *ControlledTank->GetName());

	}
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

}

// Tick
// Super
// AimTowardCrosshair();
void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardCrosshair();
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardCrosshair()
{
	if (!GetControlledTank()) { return; }
		
	FVector HitLocation; // Out parameter
	
	if(GetSightRayHitLocation(HitLocation)) // Has "side-effect", is going to line trace
	{
		UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
		
		//Tell controlled tank ti aim at this point
	}
	

}

// Get world location of linetrace through crosshair, true if it hits the landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	OutHitLocation = FVector(1.0);
	return false;
}
