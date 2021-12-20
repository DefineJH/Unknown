// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Hashing_Obj.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class FINAL_API UHashing_Obj : public UObject
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	FString GetHash(FString Name, int seed);
};
