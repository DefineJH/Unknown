// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Task_RunAwayFromPlayer.generated.h"

/**
 * 
 */
UCLASS()
class UNKNOWN_API UTask_RunAwayFromPlayer : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_RunAwayFromPlayer(FObjectInitializer const& obj_Init);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		float RunDistance = 100.f;
};
