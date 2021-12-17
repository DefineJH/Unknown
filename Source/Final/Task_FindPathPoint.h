// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Task_FindPathPoint.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API UTask_FindPathPoint : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_FindPathPoint(const FObjectInitializer& obj_initalizer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

};
