// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	AITank = GetAIController();

	if (AITank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller: %s"), *AITank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not found"));
	}

}

ATank *ATankAIController::GetAIController() const{

	return Cast<ATank>(GetPawn());
}
