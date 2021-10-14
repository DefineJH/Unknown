// Fill out your copyright notice in the Description page of Project Settings.


#include "Service_ChangeSpeed.h"
#include "Controller_AI.h"
#include "AICharacter.h"
#include "GameFramework/CharacterMovementComponent.h"


UService_ChangeSpeed::UService_ChangeSpeed()
{
	bNotifyBecomeRelevant = true;
	NodeName = TEXT("Change Speed");
}

void UService_ChangeSpeed::OnBecomeRelevant(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	Super::OnBecomeRelevant(owner_comp, node_memory);

	auto const cont = owner_comp.GetAIOwner();
	AAICharacter* npc = Cast<AAICharacter>(cont->GetPawn());
	npc->GetCharacterMovement()->MaxWalkSpeed = speed;
}

FString UService_ChangeSpeed::GetStaticServiceDescription() const
{
	return FString("Change NPCs Speed");
}

