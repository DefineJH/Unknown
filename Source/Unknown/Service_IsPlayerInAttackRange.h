// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "Service_IsPlayerInAttackRange.generated.h"

/**
 * 
 */
UCLASS()
class UNKNOWN_API UService_IsPlayerInAttackRange : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UService_IsPlayerInAttackRange();
	void OnBecomeRelevant(UBehaviorTreeComponent& owner_comp, uint8* node_memory) override;
private:
	UPROPERTY(EditAnywhere, Category = "AI", meta = (AllowPrivateAccess = "true"))
		float attack_range = 400.0f;

};
