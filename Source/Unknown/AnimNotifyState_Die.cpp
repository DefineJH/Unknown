// Fill out your copyright notice in the Description page of Project Settings.


#include "AnimNotifyState_Die.h"
#include "AICharacter.h"
#include "Unknown_GameMode.h"
#include "Kismet/GamePlayStatics.h"

FString UAnimNotifyState_Die::GetNotifyName_Implementation() const
{
	return L"Die";
}

void UAnimNotifyState_Die::NotifyTick(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float FrameDeltaTime)
{
}

void UAnimNotifyState_Die::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	AAICharacter* npc = Cast<AAICharacter>(MeshComp->GetOwner());
	if (npc)
	{
		AUnknown_GameMode* mode = Cast<AUnknown_GameMode>(UGameplayStatics::GetGameMode(MeshComp->GetWorld()));
		if (mode)
		{
			mode->DisableNPC(npc);
		}
	}
}

void UAnimNotifyState_Die::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	AAICharacter* npc = Cast<AAICharacter>(MeshComp->GetOwner());
	if (npc)
	{
		npc->Destroy();
	}
}
