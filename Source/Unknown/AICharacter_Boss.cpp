// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter_Boss.h"
#include "Controller_AI_Boss.h"
AAICharacter_Boss::AAICharacter_Boss() :AAICharacter()
{
	AIControllerClass = AController_AI_Boss::StaticClass();
	
}