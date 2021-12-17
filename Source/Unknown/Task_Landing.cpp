// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_Landing.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AICharacter_Boss.h"
#include "blackboard_keys.h"
#include "Controller_AI.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Unknown_GameMode.h"

UTask_Landing::UTask_Landing(FObjectInitializer const& obj_Init)
{
    NodeName = L"Landing";
}
EBTNodeResult::Type UTask_Landing::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
    //발리스타 비활성화
    AUnknown_GameMode* gMode = Cast<AUnknown_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
    if (gMode)
    {

    }
    auto cont = Cast<AController_AI>(owner_comp.GetAIOwner());
    auto npc = Cast<AAICharacter_Boss>(cont->GetPawn());
    npc->Play_landing();
    cont->SetCanMove(true);
    npc->CurState = EBossState::E_Ground;
    npc->SetActorLocation(FVector(npc->GetActorLocation().X, npc->GetActorLocation().Y, 8625 ));

    cont->get_blackboard()->SetValueAsBool(bb_keys::IsFlying, false);
    return EBTNodeResult::Succeeded;
}
