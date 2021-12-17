// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AICharacter.h"
#include "AICharacter_Aggressive.generated.h"

/**
 * 
 */
UCLASS()
class FINAL_API AAICharacter_Aggressive : public AAICharacter
{
	GENERATED_BODY()
	
public:
	AAICharacter_Aggressive();

	virtual void BeginAttack();
	virtual void EndAttack();
};
