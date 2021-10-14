// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "Service_ChangeSpeed.generated.h"

/**
 * 
 */
UCLASS()
class UNKNOWN_API UService_ChangeSpeed : public UBTService_BlackboardBase
{
	GENERATED_BODY()
public:
	UService_ChangeSpeed();
	void OnBecomeRelevant(UBehaviorTreeComponent& owner_comp, uint8* node_memory) override;
protected:
	FString GetStaticServiceDescription() const override;
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		float speed = 600.0f;
};
