// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Task_AttackPlayer.h"
#include "Task_AttackPlayer_Boss_Ground.generated.h"

/**
 * 
 */
UCLASS()
class UNKNOWN_API UTask_AttackPlayer_Boss_Ground : public UTask_AttackPlayer
{
	GENERATED_BODY()
public:
	UTask_AttackPlayer_Boss_Ground(FObjectInitializer const& obj_Init);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);

	bool bIsAttacking = true;
};
