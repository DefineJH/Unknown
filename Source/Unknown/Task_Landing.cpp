// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_Landing.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AICharacter_Boss.h"
#include "blackboard_keys.h"
#include "Controller_AI.h"
#include "GameFramework/CharacterMovementComponent.h"

UTask_Landing::UTask_Landing(FObjectInitializer const& obj_Init)
{
    NodeName = L"Landing";
}
EBTNodeResult::Type UTask_Landing::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
    auto cont = Cast<AController_AI>(owner_comp.GetAIOwner());
    auto npc = Cast<AAICharacter_Boss>(cont->GetPawn());
    npc->CurState = EBossState::E_Ground;
    cont->get_blackboard()->SetValueAsBool(bb_keys::IsFlying, false);
    return EBTNodeResult::Succeeded;
}
