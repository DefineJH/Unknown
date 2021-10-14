// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_IncrementPathIdx.h"
#include "Controller_AI.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "PatrolPath.h"
#include "AICharacter.h"
#include "blackboard_keys.h"
#include <math.h>


UTask_IncrementPathIdx::UTask_IncrementPathIdx(const FObjectInitializer& obj_initalizer)
{
	NodeName = TEXT("Increment Path Index");
}

EBTNodeResult::Type UTask_IncrementPathIdx::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	AController_AI* const cont = Cast<AController_AI>(OwnerComp.GetAIOwner());
	AAICharacter* const npc = Cast<AAICharacter>(cont->GetPawn());

	const int numPoints = npc->getPatrolPath()->num();
	const int minIdx = 0;
	const int maxIdx = numPoints - 1;

	int idx = cont->get_blackboard()->GetValueAsInt(bb_keys::PatrolPathIdx);

	if (biDirectional)
	{
		if (idx >= maxIdx && direction == EDirectionType::Forward)
		{
			direction = EDirectionType::Reverse;
		}
		else if (idx == minIdx && direction == EDirectionType::Reverse)
		{
			direction = EDirectionType::Forward;
		}
	}

	cont->get_blackboard()->SetValueAsInt(bb_keys::PatrolPathIdx,
		(direction == EDirectionType::Forward ? std::abs(++idx) : std::abs(--idx)) % numPoints);

	FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}
