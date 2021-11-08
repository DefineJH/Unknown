// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller_AI_Aggressive.h"
#include "blackboard_keys.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"

void AController_AI_Aggressive::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bBoard->GetValueAsBool(bb_keys::CanSeePlayer))
	{
		FVector TargetLoc = bBoard->GetValueAsVector(bb_keys::TargetLocation);
		FVector CurLoc = GetPawn()->GetActorLocation();
		FRotator TargetRot = UKismetMathLibrary::FindLookAtRotation(CurLoc, TargetLoc);
		FRotator rot = UKismetMathLibrary::RInterpTo(GetPawn()->GetActorRotation(), TargetRot, DeltaTime, 10.f);
		rot.Pitch = 0.f;
		GetPawn()->SetActorRotation(rot);
	}
}
