// Fill out your copyright notice in the Description page of Project Settings.


#include "Unknown_GameMode.h"
#include "Controller_AI.h"
#include "AICharacter.h"
#include "ObjectPool.h"


AUnknown_GameMode::AUnknown_GameMode()
{
	MonsterPool = CreateDefaultSubobject<UObjectPool>(L"MonsterPool");
	MonsterPool->CreatePool(AAICharacter::StaticClass());

	DinosaurBPClass = ConstructorHelpers::FClassFinder<ACharacter>(TEXT("/Game/AI/Dinosaur/MyFPS_AICharacter_Dinosaura")).Class;
}


void AUnknown_GameMode::DisableNPC(AAICharacter* Npc) const
{
	AController_AI* cont = Cast<AController_AI>(Npc->GetController());
	// bt , movement , sense Disable-> Controller
	if (cont)
	{
		Npc->SetActorEnableCollision(false);
		Npc->SetActorTickEnabled(false);
		cont->Disable();
	}
}

void AUnknown_GameMode::DeleteNPCFromScene(AAICharacter* Npc)
{
	FTimerDelegate TimerDel;
	FTimerHandle TimerHandle;

	TimerDel.BindUFunction(this, FName("PushNPCIntoPool"), Npc);
	GetWorldTimerManager().SetTimer(TimerHandle, TimerDel, 2.f, false);
}

void AUnknown_GameMode::SpawnMonster(FVector worldLocation)
{
	AAICharacter* npc = Cast<AAICharacter>(MonsterPool->PullOut(DinosaurBPClass, worldLocation));
	if (npc)
	{
		npc->Enable();
		AController_AI* cont = Cast<AController_AI>(npc->GetController());
		if (cont)
		{
			cont->Enable();
		}
	}
}

void AUnknown_GameMode::PushNPCIntoPool(AAICharacter* Npc)
{
	Npc->Disable();
	if (MonsterPool->PushInto(Npc))
	{
		UE_LOG(LogTemp, Warning, L"%s get into pool", *(Npc->GetName()));
	}
}

