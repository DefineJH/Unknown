// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter_Passive.h"
#include  "Controller_AI_Passive.h"
AAICharacter_Passive::AAICharacter_Passive() : AAICharacter()
{
	AIControllerClass = AController_AI_Passive::StaticClass();
}