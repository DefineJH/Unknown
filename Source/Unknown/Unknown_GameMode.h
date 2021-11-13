// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Unknown_GameMode.generated.h"

/**
 * 
 */

class AAICharacter;
class UObjectPool;

UCLASS()
class UNKNOWN_API AUnknown_GameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AUnknown_GameMode();

	void DisableNPC(AAICharacter* Npc) const;
	void DeleteNPCFromScene(AAICharacter* Npc);
	UFUNCTION(BlueprintCallable)
		void SpawnMonster(FVector worldLocation);
private:
	UFUNCTION()
		void PushNPCIntoPool(AAICharacter* Npc);
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pool")
		UObjectPool* MonsterPool;
private:
};
