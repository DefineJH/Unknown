// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Task_MakeBarrier.generated.h"

/**
 * 
 */
UCLASS()
class UNKNOWN_API UTask_MakeBarrier : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UTask_MakeBarrier(FObjectInitializer const& obj_Init);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
};
