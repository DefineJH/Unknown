// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifyState_Hit.h"

<<<<<<< HEAD
UAnimNotifyState_Hit::GetNotifyName_Implementation() const
=======
FString UAnimNotifyState_Hit::GetNotifyName_Implementation() const
>>>>>>> 32ab8088a5846fa0d8e800c708719fbc559c00ab
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
