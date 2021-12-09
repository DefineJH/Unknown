// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AICharacter_Aggressive.h"
#include "AICharacter_Boss.generated.h"

/**
 * 
 */

DECLARE_MULTICAST_DELEGATE(FOnAttackEndDelegate);
DECLARE_MULTICAST_DELEGATE(FOnTookOffEndDelegate);


UENUM(BlueprintType)
enum class EBossState : uint8
{
	E_Ground UMETA(DisplayName = "Ground"),
	E_Flying UMETA(DisplayName = "Flying")
};

UCLASS()
class UNKNOWN_API AAICharacter_Boss : public AAICharacter_Aggressive
{
	GENERATED_BODY()
public:
	AAICharacter_Boss();
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void SetInvincible();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void MakeBarrier();

	void TookOff();

	virtual void EndAttack() override;

	virtual void StartAttackAnimation() override;

public:
	UPROPERTY(BlueprintReadWrite)
	bool bIsInvincible = false;

	FOnAttackEndDelegate OnAttackEndDelegate;
	FOnTookOffEndDelegate OnTookOffEndDelegate;

	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
	UAnimMontage* FlyStationaryMontage;

	bool bIsTookOff = false;
	bool bWasOnGround = true;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	EBossState CurState;
};
