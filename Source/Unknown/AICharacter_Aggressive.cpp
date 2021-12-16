// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter_Aggressive.h"
#include "Controller_AI_Aggressive.h"
AAICharacter_Aggressive::AAICharacter_Aggressive() : AAICharacter()
{
	AIControllerClass = AController_AI_Aggressive::StaticClass();
}

void AAICharacter_Aggressive::BeginAttack()
{
	AController_AI_Aggressive* AI_Cont = Cast<AController_AI_Aggressive>(GetController());
	if (AI_Cont)
	{
		AI_Cont->bCanRotate = false;
	}
}

void AAICharacter_Aggressive::EndAttack()
{
	AController_AI_Aggressive* AI_Cont = Cast<AController_AI_Aggressive>(GetController());
	if (AI_Cont)
	{
		AI_Cont->bCanRotate = true;
	}
}
