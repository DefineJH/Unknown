// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPool.h"
#include "Kismet/KismetMathLibrary.h"
// Sets default values for this component's properties
UObjectPool::UObjectPool()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UObjectPool::BeginPlay()
{
	Super::BeginPlay();

	// ...

}


// Called every frame
void UObjectPool::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UObjectPool::CreatePool(TSubclassOf<AActor> ObjectType)
{
	DefaultPoolClass = ObjectType;
	PoolCount = 0;
}

bool UObjectPool::PushInto(UObject* PoolOBJ)
{
	if (UKismetMathLibrary::ClassIsChildOf(PoolOBJ->GetClass(), DefaultPoolClass))
	{
		PoolCount++;
		OBJ_Pool.Add(PoolOBJ);
		return true;
	}
	return false;
}

UObject* UObjectPool::PullOut(TSubclassOf<UObject> ExtractClass, FVector Location)
{
	if (UKismetMathLibrary::ClassIsChildOf(ExtractClass, DefaultPoolClass))
	{
		for (auto obj : OBJ_Pool)
		{
			if (obj->GetClass() == ExtractClass)
			{
				OBJ_Pool.Remove(obj);
				PoolCount--;
				return obj;
			}
		}
		FTransform transform;
		transform.SetLocation(Location);
		return GetWorld()->SpawnActor(ExtractClass, &transform);
	}
	else
	{
		return nullptr;
	}


}
