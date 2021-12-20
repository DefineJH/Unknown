// Fill out your copyright notice in the Description page of Project Settings.


#include "Service_IsPlayerInAttackRange.h"
#include "Controller_AI.h"
#include "AICharacter.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "blackboard_keys.h"

UService_IsPlayerInAttackRange::UService_IsPlayerInAttackRange()
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Is Player In Attack Range");
}

void UService_IsPlayerInAttackRange::OnBecomeRelevant(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	Super::OnBecomeRelevant(owner_comp, node_memory);

	AController_AI* const cont = Cast<AController_AI>(owner_comp.GetOwner());
	AAICharacter* const npc = Cast<AAICharacter>(cont->GetPawn());

	ACharacter* const Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);

	cont->get_blackboard()->SetValueAsBool(bb_keys::CanAttackPlayer,
		npc->GetDistanceTo(Player) <= attack_range);
}
