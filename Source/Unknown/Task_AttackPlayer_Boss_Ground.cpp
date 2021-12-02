// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_AttackPlayer_Boss_Ground.h"
#include "Controller_AI.h"
#include "AICharacter_Boss.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "blackboard_keys.h"
UTask_AttackPlayer_Boss_Ground::UTask_AttackPlayer_Boss_Ground(FObjectInitializer const& obj_Init) : UTask_AttackPlayer(obj_Init)
{
	NodeName = TEXT("AttackPlayer_Boss_Ground");
}

EBTNodeResult::Type UTask_AttackPlayer_Boss_Ground::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{

    AController_AI* const cont = Cast<AController_AI>(owner_comp.GetAIOwner());
    AAICharacter_Boss* const npc = Cast<AAICharacter_Boss>(cont->GetPawn());
    if (npc)
    {
        npc->StartAttackAnimation();
        npc->OnAttackEndDelegate.AddLambda([this]()-> void{ bIsAttacking = false; });
    }
    return EBTNodeResult::InProgress;
}

void UTask_AttackPlayer_Boss_Ground::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);
    if (!bIsAttacking)
    {
        FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    }
}
