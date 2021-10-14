// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Task_LookAtPlayer.generated.h"

/**
 * 
 */
UCLASS()
class UNKNOWN_API UTask_LookAtPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_LookAtPlayer(const FObjectInitializer& obj_init);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
