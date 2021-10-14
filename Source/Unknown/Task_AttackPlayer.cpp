// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_AttackPlayer.h"
#include "Controller_AI.h"
#include "AICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "blackboard_keys.h"

UTask_AttackPlayer::UTask_AttackPlayer(FObjectInitializer const& obj_Init)
{
    NodeName = TEXT("Attack Player");
}

EBTNodeResult::Type UTask_AttackPlayer::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
    AController_AI* const cont = Cast<AController_AI>(owner_comp.GetAIOwner());
    AAICharacter* const npc = Cast<AAICharacter>(cont->GetPawn());

    npc->StartAttackAnimation();

    FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);

    return EBTNodeResult::Succeeded;
}
