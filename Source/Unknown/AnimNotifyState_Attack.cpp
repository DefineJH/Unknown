// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifyState_Attack.h"
#include "AICharacter.h"
#include "Controller_AI.h"

FString UAnimNotifyState_Attack::GetNotifyName_Implementation() const
{
	return L"Attack";
}

void UAnimNotifyState_Attack::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime);
}

void UAnimNotifyState_Attack::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	AAICharacter* npc = Cast<AAICharacter>(MeshComp->GetOwner());
	if (npc)
	{
		AController_AI* cont = Cast<AController_AI>(npc->GetController());
		npc->BeginAttack();
		if (cont)
		{
			cont->SetCanMove(false);
		}
	}
}

void UAnimNotifyState_Attack::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	AAICharacter* npc = Cast<AAICharacter>(MeshComp->GetOwner());
	if (npc)
	{
		AController_AI* cont = Cast<AController_AI>(npc->GetController());
		npc->EndAttack();
		if (cont)
		{
			cont->SetCanMove(true);

		}
	}
}
