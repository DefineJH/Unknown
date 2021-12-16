// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_AttackFromSky.h"
#include "AICharacter_Boss.h"
#include "Controller_AI.h"
UTask_AttackFromSky::UTask_AttackFromSky(FObjectInitializer const& obj_Init)
{
    NodeName = TEXT("AttackFromSky");
    bNotifyTick = true;
}

void UTask_AttackFromSky::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

    if (bFinished)
    {
        FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
    }
}

EBTNodeResult::Type UTask_AttackFromSky::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
    AController_AI* const cont = Cast<AController_AI>(owner_comp.GetAIOwner());
    AAICharacter_Boss* const boss = Cast<AAICharacter_Boss>(cont->GetPawn());
    if (boss)
    {
        boss->OnSkyAttackEndDelegate.AddLambda([this]()-> void { bFinished = true; });
        boss->StartSkyAttackAnimation();
    }
    return EBTNodeResult::Type::InProgress;
}
