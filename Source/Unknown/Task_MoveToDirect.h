// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "Task_MoveToDirect.generated.h"

/**
 * 
 */
UCLASS()
class UNKNOWN_API UTask_MoveToDirect : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_MoveToDirect(FObjectInitializer const& obj_Init);
	void TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int AcceptanceRadius = 50;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FVector Destination;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bMoveToPatrol = true;
private:
	FVector Dest;
	bool bReached = false;
	const UBlackboardComponent* MyBlackboard;
	
};
