// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
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
	void OnAttacked();
	virtual void Tick(float DeltaSeconds) override;
	UBlackboardComponent* get_blackboard() const;
	void SetCanMove(bool CanMove);

	void Disable();
	void Enable();
private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		UBehaviorTreeComponent* behaviorTreeComp;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		UBehaviorTree* bTree;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
		UBlackboardComponent* bBoard;

	UAISenseConfig_Sight* sight_config;

	bool bCanMove = true;
private:
	//this function called when enemy has detected player
	UFUNCTION()
		void on_target_detected(AActor* actor, FAIStimulus const stimulus);

	void setup_perception_system();

};
