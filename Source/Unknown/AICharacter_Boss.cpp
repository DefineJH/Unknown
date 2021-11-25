// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter_Boss.h"
#include "Controller_AI_Boss.h"
AAICharacter_Boss::AAICharacter_Boss() :AAICharacter()
{
	AIControllerClass = AController_AI_Boss::StaticClass();
	
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

void AAICharacter_Boss::MakeBarrier_Implementation()
{
}
