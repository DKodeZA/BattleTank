// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	AITank = GetAIController();
	PlayerTank = GetPlayerTank();

	if (AITank) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller: %s"), *AITank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not found"));
	}

	if (PlayerTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Tank: %s"), *PlayerTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI could not find Player Tank"));
	}

}

ATank *ATankAIController::GetAIController() const{

	return Cast<ATank>(GetPawn());
}

ATank *ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
