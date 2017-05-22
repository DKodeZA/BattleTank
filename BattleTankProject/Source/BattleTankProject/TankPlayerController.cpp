// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();
	PlayerTank = GetControlledTank();

	if (PlayerTank!=nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Player Pawn: %s"), *PlayerTank->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player Pawn not found"));
	}
}


ATank *ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

