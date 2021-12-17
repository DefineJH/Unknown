// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ObjectPool.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class FINAL_API UObjectPool : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UObjectPool();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void CreatePool(TSubclassOf<AActor> ObjectType);

	// DefaultPoolClass의 자식 클래스만 허용
	UFUNCTION(BlueprintCallable)
		bool PushInto(UObject* PoolOBJ);

	/* ExtractClass 와 일치하는 클래스를 가진 오브젝트만 풀에서 추출
	*  없을 시 새로운 오브젝트 만들어서 반환.
	*  만약 ExtractClass가 DefaultPoolClass의 자식이 아닐경우 nullptr 반환
	*/
	UFUNCTION(BlueprintCallable)
		UObject* PullOut(TSubclassOf<UObject> ExtractClass, FVector Location);
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pool")
		int PoolCount;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Pool")
		TSubclassOf<UObject> DefaultPoolClass;
private:
	TArray<UObject*> OBJ_Pool;
};
