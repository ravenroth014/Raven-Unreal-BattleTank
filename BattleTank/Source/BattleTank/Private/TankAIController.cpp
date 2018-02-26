// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"


ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

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
}
