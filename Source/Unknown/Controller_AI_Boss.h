// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Controller_AI.h"
#include "Controller_AI_Boss.generated.h"

/**
 * 
 */
UCLASS()
class UNKNOWN_API AController_AI_Boss : public AController_AI
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaSeconds) override;
	void SetInvincible();
	void DisableInvincible();
};
