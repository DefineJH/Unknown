// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "Controller_AI.generated.h"

/**
 * 
 */

class UBlackboardComponent;
class UBehaviorTreeComponent;
class UAISenseConfig_Sight;
struct FAIStimulus;

UCLASS()
class UNKNOWN_API AController_AI : public AAIController
{
	GENERATED_BODY()
public:
	AController_AI(const FObjectInitializer& obj_initalizer = FObjectInitializer::Get());
	virtual void BeginPlay() override;
	void OnPossess(APawn* const InPawn);
	virtual void OnAttacked();
	virtual void Tick(float DeltaSeconds) override;
	virtual UBlackboardComponent* get_blackboard() const;
	virtual void SetCanMove(bool CanMove);

	virtual void Disable();
	virtual void Enable();
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI", meta = (AllowProtectedAccess = "true"))
	UBehaviorTreeComponent* behaviorTreeComp;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI", meta = (AllowProtectedAccess = "true"))
	UBehaviorTree* bTree;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "AI", meta = (AllowProtectedAccess = "true"))
	UBlackboardComponent* bBoard;

	UAISenseConfig_Sight* sight_config;

	bool bCanMove = true;

	
protected:
	//this function called when enemy has detected player
	UFUNCTION()
	void on_target_detected(AActor* actor, FAIStimulus const stimulus);

	void setup_perception_system();

};
