// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifyState_TookOff.h"
#include "AICharacter_Boss.h"
FString UAnimNotifyState_TookOff::GetNotifyName_Implementation() const
{
	return L"TookOff";
}

void UAnimNotifyState_TookOff::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
	Super::NotifyTick(MeshComp, Animation, FrameDeltaTime);
}

void UAnimNotifyState_TookOff::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	AAICharacter_Boss* npc = Cast<AAICharacter_Boss>(MeshComp->GetOwner());
	if (npc)
	{
		npc->bIsTookOff = true;
	}
}

void UAnimNotifyState_TookOff::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);
	AAICharacter_Boss* npc = Cast<AAICharacter_Boss>(MeshComp->GetOwner());
	if (npc)
	{
		npc->bIsTookOff = false;
	}
}
