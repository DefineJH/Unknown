// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_TookOff.h"
#include "blackboard_keys.h"
#include "Controller_AI.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AICharacter_Boss.h"
UTask_TookOff::UTask_TookOff(FObjectInitializer const& obj_Init)
{
	bNotifyTick = true;
	NodeName = TEXT("Took Off");
}

void UTask_TookOff::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
	if (bReached)
	{
		auto cont = Cast<AController_AI>(OwnerComp.GetAIOwner());
		if (cont)
		{
			cont->get_blackboard()->SetValueAsBool(bb_keys::IsFlying, true);
		}
		FinishLatentTask(OwnerComp,EBTNodeResult::Succeeded);
	}
}

EBTNodeResult::Type UTask_TookOff::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	auto cont = Cast<AAIController>(owner_comp.GetAIOwner());
	auto npc = Cast<AAICharacter_Boss>(cont->GetPawn());
	if (cont)
	{
		npc->TookOff();
		npc->GetCharacterMovement()->SetMovementMode(EMovementMode::MOVE_Flying);

		npc->OnTookOffEndDelegate.AddLambda([this]()-> void { 
			bReached = true; });
	}
	return EBTNodeResult::InProgress;
}
