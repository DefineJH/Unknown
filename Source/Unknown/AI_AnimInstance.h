// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AI_AnimInstance.generated.h"

/**
 * 
 */

class UAnimMontage;

UCLASS()
class UNKNOWN_API UAI_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UAI_AnimInstance();

	virtual void NativeBeginPlay() override;
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	UFUNCTION(BlueprintNativeEvent)
	void Play_Attack_Anim();
	UFUNCTION()
	void Play_Dead_Anim();
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite)
		UAnimMontage* AttackMontage;
	UPROPERTY(EditDefaultsOnly)
		UAnimMontage* DieMontage;
private:
	bool bIsAttack;
};
