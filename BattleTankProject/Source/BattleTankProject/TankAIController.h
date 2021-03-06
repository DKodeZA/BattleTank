// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKPROJECT_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	

public:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;
	
private:
	ATank *GetAITank() const;
	ATank *GetPlayerTank() const;
	
};
