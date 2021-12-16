// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller_AI_Boss.h"
#include "blackboard_keys.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"

void AController_AI_Boss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector TargetLoc = bBoard->GetValueAsVector(bb_keys::TargetLocation);
	FVector CurLoc = GetPawn()->GetActorLocation();
	FRotator TargetRot = UKismetMathLibrary::FindLookAtRotation(CurLoc, TargetLoc);
	FRotator rot = UKismetMathLibrary::RInterpTo(GetPawn()->GetActorRotation(), TargetRot, DeltaTime, 10.f);
	rot.Pitch = 0.f;
	GetPawn()->SetActorRotation(rot);
}

void AController_AI_Boss::SetInvincible()
{
	bBoard->SetValueAsBool(bb_keys::IsInvincible, true);
}

void AController_AI_Boss::DisableInvincible()
{
	bBoard->SetValueAsBool(bb_keys::IsInvincible, false);
}
