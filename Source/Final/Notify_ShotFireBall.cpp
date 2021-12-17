// Fill out your copyright notice in the Description page of Project Settings.


#include "Notify_ShotFireBall.h"
#include "AICharacter_Boss.h"
FString UNotify_ShotFireBall::GetNotifyName_Implementation() const
{
	return L"ShotFireBall";
}

void UNotify_ShotFireBall::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	AAICharacter_Boss* boss = Cast<AAICharacter_Boss>(MeshComp->GetOwner());
	if (boss)
	{
		boss->ShotFireBall();
	}
}
