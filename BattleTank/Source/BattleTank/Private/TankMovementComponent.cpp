// Fill out your copyright notice in the Description page of Project Settings.

#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialize(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
    if (!LeftTrackToSet || !RightTrackToSet)
    {
        return;
    }
    RightTrack = RightTrackToSet;
    LeftTrack = LeftTrackToSet;
}

void UTankMovementComponent::IntendMoveForward(float Throw)
{
    UE_LOG(LogTemp, Warning, TEXT("Intend move forward throw: %f"), Throw);
    Throw = FMath::Clamp(Throw, -1, 1);
    LeftTrack->SetThrottle(Throw);
    RightTrack->SetThrottle(Throw);
}
void UTankMovementComponent::IntendMoveBackward(float Throw)
{
    UE_LOG(LogTemp, Warning, TEXT("Intend move backward throw: %f"), Throw);
    Throw = FMath::Clamp(Throw, -1, 1);
    LeftTrack->SetThrottle(Throw*-1);
    RightTrack->SetThrottle(Throw*-1);
}

void UTankMovementComponent::IntendMoveLeft(float Throw)
{
    UE_LOG(LogTemp, Warning, TEXT("Intend move left throw: %f"), Throw);
    Throw = FMath::Clamp(Throw, -1, 1);
    RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendMoveRight(float Throw)
{
    UE_LOG(LogTemp, Warning, TEXT("Intend move right throw: %f"), Throw);
    Throw = FMath::Clamp(Throw, -1, 1);
    LeftTrack->SetThrottle(Throw);

}
