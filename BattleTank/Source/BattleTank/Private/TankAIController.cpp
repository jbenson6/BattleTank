// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "Engine.h"
#include "Tank.h"

void ATankAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
    auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
    auto ControlledTank = Cast<ATank>(GetPawn());
    if (PlayerTank)
    {
        MoveToActor(PlayerTank, AcceptanceRadius, true, true, false, 0, true);
        ControlledTank->AimAt(PlayerTank->GetActorLocation());
        //Fire if ready
        ControlledTank->Fire();
    }
}