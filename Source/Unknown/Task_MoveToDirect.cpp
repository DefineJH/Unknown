// Fill out your copyright notice in the Description page of Project Settings.


#include "Task_MoveToDirect.h"
#include "blackboard_keys.h"
#include "Controller_AI.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AICharacter_Boss.h"
#include "Kismet/KismetMathLibrary.h"

UTask_MoveToDirect::UTask_MoveToDirect(FObjectInitializer const& obj_Init)
{
	bNotifyTick = true;
	NodeName = L"MoveToDirect";

	BlackboardKey.AddObjectFilter(this, GET_MEMBER_NAME_CHECKED(UTask_MoveToDirect, BlackboardKey), AActor::StaticClass());
	BlackboardKey.AddVectorFilter(this, GET_MEMBER_NAME_CHECKED(UTask_MoveToDirect, BlackboardKey));
}

void UTask_MoveToDirect::TickTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickTask(OwnerComp, NodeMemory, DeltaSeconds);

	auto cont = Cast<AController_AI>(OwnerComp.GetAIOwner());
	auto npc = Cast<AAICharacter_Boss>(cont->GetPawn());
	if (!bMoveToPatrol)
	{
		Dest = Destination;
	}

	if (npc)
	{
		if (UKismetMathLibrary::Vector_Distance(Dest, npc->GetActorLocation()) <= AcceptanceRadius)
		{
			FinishLatentTask(OwnerComp, EBTNodeResult::Succeeded);
		}
		else
		{
			FVector MoveDirect = (Dest - (npc->GetActorLocation()));
			MoveDirect.Normalize();
			FVector CurLoc = npc->GetActorLocation();
			npc->SetActorLocation(CurLoc + (MoveDirect * 20.f));
			FRotator TargetRot = UKismetMathLibrary::FindLookAtRotation(CurLoc, Dest);
			FRotator rot = UKismetMathLibrary::RInterpTo(npc->GetActorRotation(), TargetRot, DeltaSeconds, 100.f);
			rot.Pitch = 0.f;
			npc->SetActorRotation(rot);
		}
	}
}

EBTNodeResult::Type UTask_MoveToDirect::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	MyBlackboard = owner_comp.GetBlackboardComponent();

	auto cont = Cast<AController_AI>(owner_comp.GetAIOwner());
	auto npc = Cast<AAICharacter_Boss>(cont->GetPawn());
	if (cont)
	{
		Dest = cont->get_blackboard()->GetValueAsVector(bb_keys::PatrolPathVector);
	}
	return EBTNodeResult::InProgress;
}
