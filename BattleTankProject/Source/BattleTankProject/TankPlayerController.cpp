// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTankProject.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() {

	Super::BeginPlay();

	if (GetControlledTank() != nullptr) {
		UE_LOG(LogTemp, Warning, TEXT("Player Pawn: %s"), *GetControlledTank()->GetName());
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("Player Pawn not found"));
	}
}

void ATankPlayerController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	//UE_LOG(LogTemp, Warning, TEXT("Ticking"));
	AimTowardsCrosshair();

}

ATank *ATankPlayerController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() {
	if (!GetControlledTank()) { return; }

	FVector HitLocation;

	if (GetSightRayHitLocation(HitLocation)) {
		GetControlledTank()->AimAt(HitLocation);
	}
	
}

bool ATankPlayerController::GetSightRayHitLocation(FVector &HitLocation) const{
	FHitResult HitResult;

	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D(ViewportSizeX*CrosshairXLocation, ViewportSizeY*CrosshairYLocation);
	FVector LookDirection;

	if (GetLookDirection(ScreenLocation, LookDirection)) {

		GetLookVectorHitLocation(LookDirection, HitLocation);
	}
	return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector &LookDirection) const{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, CameraWorldLocation, LookDirection);
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector &TargetLocation) const{
	FHitResult HitResult;
	FVector TraceStart = PlayerCameraManager->GetCameraLocation();
	FVector TraceEnd = TraceStart+(LookDirection*LineTraceRange);
	bool isHit = GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility);
	if (isHit) {
		TargetLocation = HitResult.Location;
	}
	else {
		TargetLocation = FVector(0.f);
	}
	return isHit;
}