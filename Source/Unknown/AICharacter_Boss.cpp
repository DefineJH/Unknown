// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter_Boss.h"
#include "Controller_AI_Boss.h"
#include "AI_AnimInstance.h"
AAICharacter_Boss::AAICharacter_Boss() : AAICharacter_Aggressive()
{
	AIControllerClass = AController_AI_Boss::StaticClass();
	CurState = EBossState::E_Ground;
}

void AAICharacter_Boss::SetInvincible()
{
	AController_AI_Boss* cont = Cast<AController_AI_Boss>(GetController());
	if (cont)
	{
		cont->SetInvincible();
	}
	bIsInvincible = true;
}

void AAICharacter_Boss::DisableInvincible()
{
	AController_AI_Boss* cont = Cast<AController_AI_Boss>(GetController());
	if (cont)
	{
		cont->DisableInvincible();
	}
	bIsInvincible = false;
}

void AAICharacter_Boss::TookOff()
{
	auto animInst = Cast<UAI_AnimInstance>(GetMesh()->GetAnimInstance());
	if (animInst)
	{
		if (FlyStationaryMontage)
		{
			animInst->Montage_Play(FlyStationaryMontage);
		}
	}
}

void AAICharacter_Boss::EndAttack()
{
	OnAttackEndDelegate.Broadcast();
}

void AAICharacter_Boss::StartAttackAnimation()
{

	Super::StartAttackAnimation();
}

void AAICharacter_Boss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsTookOff)
	{
		FVector NewLoc = GetActorLocation() + FVector(0, 0, 6);
		SetActorLocation(NewLoc);
		if (GetActorLocation().Z > 3050 && GetMesh()->GetAnimInstance()->Montage_IsPlaying(FlyStationaryMontage))
		{
			CurState = EBossState::E_Flying;
			GetMesh()->GetAnimInstance()->Montage_Stop(1);
			OnTookOffEndDelegate.Broadcast();
		}
	}
}

void AAICharacter_Boss::MakeBarrier_Implementation()
{
}
