// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Controller_AI.h"
#include "Controller_AI_Aggressive.generated.h"

/**
 * 
 */
UCLASS()
class UNKNOWN_API AController_AI_Aggressive : public AController_AI
{
	GENERATED_BODY()
public:
	virtual void Tick(float DeltaSeconds) override;
public:
	bool bCanRotate = true;
};
