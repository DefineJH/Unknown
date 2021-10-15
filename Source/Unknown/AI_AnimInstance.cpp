// Fill out your copyright notice in the Description page of Project Settings.


#include "AI_AnimInstance.h"
#include "Animation/AnimMontage.h"

UAI_AnimInstance::UAI_AnimInstance()
{
	bIsAttack = false;
	ConstructorHelpers::FObjectFinder<UAnimMontage> montage(TEXT("AnimMontage'/Game/AI/AI/Dinosaur/AttackMontage.AttackMontage'"));
	if (montage.Succeeded())
	{
		AttackMontage = montage.Object;
	}
}

void UAI_AnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();
}

void UAI_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UAI_AnimInstance::Play_Attack_Anim()
{
	if (AttackMontage)
	{
		Montage_Play(AttackMontage);
	}
}

void UAI_AnimInstance::Play_Dead_Anim()
{
	if (DieMontage)
	{
		Montage_Play(DieMontage);
	}
}

