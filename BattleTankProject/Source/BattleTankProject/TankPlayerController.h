// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKPROJECT_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank *GetControlledTank() const;

	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	
private:
	ATank *PlayerTank = nullptr;

	UPROPERTY(EditAnywhere)
	float CrosshairXLocation = 0.5f;
	UPROPERTY(EditAnywhere)
	float CrosshairYLocation = 0.33333f;

	//Move barrel to crosshair
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector&)const;
	bool GetLookDirection(FVector2D, FVector&) const;
};
