// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Task_TookOff.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API UTask_TookOff : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UTask_TookOff(FObjectInitializer const& obj_Init);
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);
private:
	bool bReached = false;
};
