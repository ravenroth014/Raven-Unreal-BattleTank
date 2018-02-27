// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();	

	AITank = GetControllerTank();

	if(!AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller not possess"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller possessing in %s"), *AITank->GetName());
	}
}

void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (GetPlayerTank()) {

		// TODO: Move towards the player

		// Aim towards the player
		AITank->AimAt(GetPlayerTank()->GetActorLocation());

		// Fire when ready
	}
}


ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if(!PlayerPawn) {return nullptr;}
	return Cast<ATank>(PlayerPawn);
}