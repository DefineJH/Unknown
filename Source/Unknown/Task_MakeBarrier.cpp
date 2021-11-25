// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_MakeBarrier.h"


UTask_MakeBarrier::UTask_MakeBarrier(FObjectInitializer const& obj_Init)
{
	NodeName = TEXT("Make Barrier");
}

EBTNodeResult::Type UTask_MakeBarrier::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	return EBTNodeResult::Succeeded;
}
