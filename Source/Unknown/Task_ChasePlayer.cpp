// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_ChasePlayer.h"
#include "Controller_AI.h"
#include "AICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "blackboard_keys.h"

UTask_ChasePlayer::UTask_ChasePlayer(FObjectInitializer const& obj_Init)
{
	NodeName = TEXT("Chase Player");
}

EBTNodeResult::Type UTask_ChasePlayer::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	AController_AI* const cont = Cast<AController_AI>(owner_comp.GetAIOwner());
	const FVector player_loc = cont->get_blackboard()->GetValueAsVector(bb_keys::TargetLocation);

	UE_LOG(LogTemp, Warning, L"Called Chase Player");

	FAIMoveRequest mq;
	mq.SetGoalLocation(player_loc);
	mq.SetAcceptanceRadius(StopRange);
	mq.SetStopOnOverlap(true);
	cont->MoveTo(mq);

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
