// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "Task_IncrementPathIdx.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API UTask_IncrementPathIdx : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
public:
	UTask_IncrementPathIdx(const FObjectInitializer& obj_initalizer);
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory);

private:
	enum class EDirectionType
	{
		Forward,
		Reverse
	};
	EDirectionType direction = EDirectionType::Forward;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		bool biDirectional = true;
};
