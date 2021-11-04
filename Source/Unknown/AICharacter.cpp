// Fill out your copyright notice in the Description page of Project Settings.


#include "AICharacter.h"
#include "PatrolPath.h"
#include "AI_AnimInstance.h"
#include "Controller_AI.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "Components/BoxComponent.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AAICharacter::AAICharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bUseControllerRotationYaw = false;
	//GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	//HealthComp = CreateDefaultSubobject<UHealthComponent>(L"HealthComp");
}

// Called when the game starts or when spawned
void AAICharacter::BeginPlay()
{
	Super::BeginPlay();
	//개선필요
	TArray<AActor*> paths;
	UGameplayStatics::GetAllActorsWithTag(GetWorld(), L"PatrolPath", paths);
	SpawnDefaultController();
	for (auto obj : paths)
	{
		APatrolPath* path = Cast<APatrolPath>(obj);
		if (path)
		{
			patrolPath = path;
		}
	}

}



// Called every frame
void AAICharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAICharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

APatrolPath* AAICharacter::getPatrolPath()
{
	return patrolPath;
}


void AAICharacter::BeginAttack()
{
}

void AAICharacter::EndAttack()
{
}

void AAICharacter::StartAttackAnimation()
{
	auto* const animInst = Cast<UAI_AnimInstance>(GetMesh()->GetAnimInstance());
	animInst->Play_Attack_Anim();
}

void AAICharacter::StartDieAnimation()
{
	auto* const animInst = Cast<UAI_AnimInstance>(GetMesh()->GetAnimInstance());
	animInst->Play_Dead_Anim();
}

void AAICharacter::Enable()
{
	GetMesh()->GetAnimInstance()->Montage_Stop(0.f);
	GetMesh()->SetVisibility(true);
	SetActorEnableCollision(true);
	//HealthComp->Reset();
}

void AAICharacter::Disable()
{
	GetMesh()->SetVisibility(false);
}


