// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Task_AttackFromSky.generated.h"

/**
 * 
 */
UCLASS()
class UNKNOWN_API UTask_AttackFromSky : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	UTask_AttackFromSky(FObjectInitializer const& obj_Init);
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);

public:
	bool bFinished = false;
};
