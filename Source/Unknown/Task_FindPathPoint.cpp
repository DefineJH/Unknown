// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_FindPathPoint.h"
#include "Controller_AI.h"
#include "AICharacter.h"
#include "PatrolPath.h"
#include "blackboard_keys.h"
#include "BehaviorTree/BlackboardComponent.h"

UTask_FindPathPoint::UTask_FindPathPoint(const FObjectInitializer& obj_initalizer)
{
	NodeName = TEXT("Find Patrol Path Point");
}

EBTNodeResult::Type UTask_FindPathPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto* cont = Cast<AController_AI>(OwnerComp.GetAIOwner());

	const int idx = cont->get_blackboard()->GetValueAsInt(bb_keys::PatrolPathIdx);

	AAICharacter* const npc = Cast<AAICharacter>(cont->GetPawn());

	// patrol point 는 부모 객체에 relative 한 position 으로 주어지므로 역변환하여 world position 으로 변환후
	// 이동해야 함.
	const FVector point = npc->getPatrolPath()->getPatrolPoints(idx);

	const FVector world_Point = npc->getPatrolPath()->GetActorTransform().TransformPosition(point);

	cont->get_blackboard()->SetValueAsVector(bb_keys::PatrolPathVector, world_Point);

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
