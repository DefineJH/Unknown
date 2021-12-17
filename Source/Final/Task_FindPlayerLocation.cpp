// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_FindPlayerLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"
#include "Controller_AI.h"
#include "blackboard_keys.h"

UTask_FindPlayerLocation::UTask_FindPlayerLocation(FObjectInitializer const& obj_Init)
{
	NodeName = TEXT("Find Player Location");
}

EBTNodeResult::Type UTask_FindPlayerLocation::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	ACharacter* const Player = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	AController_AI* const cont = Cast<AController_AI>(owner_comp.GetAIOwner());

	const FVector playerLoc = Player->GetActorLocation();

	if (search_random)
	{
		FNavLocation loc;
		UNavigationSystemV1* nav_sys = UNavigationSystemV1::GetCurrent(GetWorld());
		if (nav_sys->GetRandomPointInNavigableRadius(playerLoc, search_radius, loc, nullptr))
		{
			cont->get_blackboard()->SetValueAsVector(bb_keys::TargetLocation, loc.Location);
		}
	}
	else
	{
		cont->get_blackboard()->SetValueAsVector(bb_keys::TargetLocation, playerLoc);
	}

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);
	return EBTNodeResult::Succeeded;
}

