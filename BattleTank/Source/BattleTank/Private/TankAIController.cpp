// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	const auto AITank = GetControllerTank();

	if(!AITank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller not possess"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI controller possessing in %s"), *AITank->GetName());
	}

	const auto PlayerTank = GetPlayerTank();

	if(!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Player's tank is not found in this world"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found player's tank, codename: %s"),*PlayerTank->GetName());
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