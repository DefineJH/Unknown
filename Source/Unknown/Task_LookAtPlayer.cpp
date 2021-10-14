// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_LookAtPlayer.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Controller_AI.h"
#include "blackboard_keys.h"

UTask_LookAtPlayer::UTask_LookAtPlayer(const FObjectInitializer& obj_init)
{
	NodeName = TEXT("LookAtPlayer");
}

EBTNodeResult::Type UTask_LookAtPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto* cont = Cast<AController_AI>(OwnerComp.GetAIOwner());
	auto* const npc = cont->GetPawn();

	FVector playerLoc = cont->get_blackboard()->GetValueAsVector(bb_keys::TargetLocation);
	FRotator Rotator = UKismetMathLibrary::FindLookAtRotation(cont->GetPawn()->GetActorLocation(), playerLoc);
	Rotator.Pitch = 0.0f;
	npc->SetActorRotation(Rotator, ETeleportType::ResetPhysics);

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
