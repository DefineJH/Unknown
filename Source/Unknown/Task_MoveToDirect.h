// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "Task_MoveToDirect.generated.h"

/**
 * 
 */
UCLASS()
class UNKNOWN_API UTask_MoveToDirect : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UTask_MoveToDirect(FObjectInitializer const& obj_Init);
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	int AcceptanceRadius = 50;
private:
	FVector Dest;
	bool bReached = false;
};
