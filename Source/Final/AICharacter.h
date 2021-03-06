// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AICharacter.generated.h"

class APatrolPath;
UCLASS()
class FINAL_API AAICharacter : public ACharacter
{
	GENERATED_BODY()


public:
		// Sets default values for this character's properties
	AAICharacter();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	APatrolPath* getPatrolPath();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		APatrolPath* patrolPath;



	virtual void StartAttackAnimation();

	virtual void StartDieAnimation();


	virtual void Enable();
	virtual void Disable();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//virtual void SetupBoxColliders();
protected:



	float AttackMeleeDamage = 1.5f;
	float MaxHealth = 100.0f;
	float CurHealth = 100.0f;

};
