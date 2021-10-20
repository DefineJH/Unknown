// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_RunAwayFromPlayer.h"
#include "Controller_AI.h"
#include "blackboard_keys.h"
#include "BehaviorTree/BlackboardComponent.h"

UTask_RunAwayFromPlayer::UTask_RunAwayFromPlayer(FObjectInitializer const& obj_Init)
{
	NodeName = TEXT("RunAway");
}
EBTNodeResult::Type UTask_RunAwayFromPlayer::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	AController_AI* const cont = Cast<AController_AI>(owner_comp.GetAIOwner());
	UBlackboardComponent* bb = cont->get_blackboard();
	const FVector player_loc = bb->GetValueAsVector(bb_keys::TargetLocation);
	const FVector CurLoc = cont->GetPawn()->GetActorLocation();
	
	FVector RunVector = CurLoc - player_loc;
	RunVector = RunVector.GetSafeNormal();

	RunVector = CurLoc + RunVector * RunDistance;

	FAIMoveRequest mq;
	mq.SetGoalLocation(RunVector);
	mq.SetAcceptanceRadius(10.0f);
	mq.SetStopOnOverlap(true);
	cont->MoveTo(mq);

	bb->SetValueAsBool(bb_keys::IsRunning, true);

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded; 


}
