// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AICharacter_Aggressive.h"
#include "AICharacter_Boss.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);


UCLASS()
class UNKNOWN_API AAICharacter_Boss : public AAICharacter_Aggressive
{
	GENERATED_BODY()
public:
	AAICharacter_Boss();
	UFUNCTION(BlueprintCallable)
	void SetInvincible();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void MakeBarrier();

	virtual void EndAttack() override;

	virtual void StartAttackAnimation() override;
public:
	UPROPERTY(BlueprintReadWrite)
	bool bIsInvincible = false;

	FOnAttackEndDelegate OnAttackEndDelegate;

};
