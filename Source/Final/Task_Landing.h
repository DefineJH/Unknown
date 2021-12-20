// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Task_Landing.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API UTask_Landing : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_Landing(FObjectInitializer const& obj_Init);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);

};
