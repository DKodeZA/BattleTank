// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay() {
	Super::BeginPlay();


	if (GetAITank()) {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller: %s"), *GetAITank()->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI Controller not found"));
	}

	if (GetPlayerTank()) {
		UE_LOG(LogTemp, Warning, TEXT("Player Tank: %s"), *GetPlayerTank()->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AI could not find Player Tank"));
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	if (GetPlayerTank()) {
		GetAITank()->AimAt(GetPlayerTank()->GetActorLocation());
	}
}

ATank *ATankAIController::GetAITank() const{

	return Cast<ATank>(GetPawn());
}

ATank *ATankAIController::GetPlayerTank() const {
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
