// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_TookOff.h"

UTask_TookOff::UTask_TookOff(FObjectInitializer const& obj_Init)
{
	NodeName = TEXT("Took Off");
}

EBTNodeResult::Type UTask_TookOff::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	return EBTNodeResult::Succeeded;
}
