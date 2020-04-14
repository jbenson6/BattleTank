// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "Engine.h"
#include "Tank.h"


ATank *ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AIController not possessing tank"));
	}
	//UE_LOG(LogTemp, Warning, TEXT("AIController Tank: %s"), *ControlledTank->GetName());

    // Find Player Tank
    auto PlayerTank = FindPlayerControllerTank();
    if(!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("No PlayerTank Found"));
    }
    //UE_LOG(LogTemp, Warning, TEXT("PlayerTank Found: %s"), *PlayerTank->GetName())
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
    if(FindPlayerControllerTank())
    GetControlledTank()->AimAt(FindPlayerControllerTank()->GetActorLocation());
}

ATank* ATankAIController::FindPlayerControllerTank()
{
    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    if(!PlayerTank)
    {
        UE_LOG(LogTemp, Warning, TEXT("No PlayerTank Found"));
        return nullptr;
    }
    return PlayerTank;
}