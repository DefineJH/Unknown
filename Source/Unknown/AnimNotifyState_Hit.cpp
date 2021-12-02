// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifyState_Hit.h"



FString UAnimNotifyState_Hit::GetNotifyName_Implementation() const

{
	return L"Hit";
}

void UAnimNotifyState_Hit::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
}

void UAnimNotifyState_Hit::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
}

void UAnimNotifyState_Hit::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
}
