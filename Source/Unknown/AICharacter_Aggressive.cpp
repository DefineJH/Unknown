// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter_Aggressive.h"
#include "Controller_AI_Aggressive.h"

AAICharacter_Aggressive::AAICharacter_Aggressive() : AAICharacter()
{
	AIControllerClass = AController_AI_Aggressive::StaticClass();
}


