// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPath.generated.h"

UCLASS()
class UNKNOWN_API APatrolPath : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	APatrolPath();

	FVector getPatrolPoints(const int idx) const;
	int num() const;
private:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI", meta = (MakeEditWidget = "true", AllowPrivateAccess = "true"))
		TArray<FVector> patrolPoints;

};
