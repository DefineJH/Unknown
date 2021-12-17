// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotify_AttackEnd.h"
#include "AICharacter_Boss.h"

FString UAnimNotify_AttackEnd::GetNotifyName_Implementation() const
{
	return L"AttackEnd";
}


void UAnimNotify_AttackEnd::Notify(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	AAICharacter_Boss* boss = Cast<AAICharacter_Boss>(MeshComp->GetOwner());
	if (boss)
	{
		UE_LOG(LogTemp, Warning, L"ADSDWDS");
		boss->OnSkyAttackEndDelegate.Broadcast();
	}
}
