// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_MakeBarrier.h"
#include "Controller_AI_Boss.h"
#include "AICharacter_Boss.h"

UTask_MakeBarrier::UTask_MakeBarrier(FObjectInitializer const& obj_Init)
{
	NodeName = TEXT("Make Barrier");
}

EBTNodeResult::Type UTask_MakeBarrier::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	auto cont = Cast<AController_AI_Boss>(owner_comp.GetAIOwner());
	auto npc = Cast<AAICharacter_Boss>(cont->GetPawn());
	if (cont)
	{
		cont->SetCanMove(false);
		npc->MakeBarrier();
	}
	return EBTNodeResult::Succeeded;
}

void UTask_MakeBarrier::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

}
