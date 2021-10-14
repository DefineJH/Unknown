// Fill out your copyright notice in the Description page of Project Settings.


#include "Controller_AI.h"
#include "blackboard_keys.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionStimuliSourceComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "GameFramework/Character.h"

AController_AI::AController_AI(const FObjectInitializer& obj_initalizer /*= FObjectInitializer::Get()*/)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> obj(TEXT("BehaviorTree'/Game/AI/BB/FPS_BT.FPS_BT'"));
	if (obj.Succeeded())
	{
		bTree = obj.Object;
	}
	behaviorTreeComp = obj_initalizer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	bBoard = obj_initalizer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackBoardComp"));
	setup_perception_system();

}

void AController_AI::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(bTree);
	behaviorTreeComp->StartTree(*bTree);
}

void AController_AI::OnPossess(APawn* const InPawn)
{
	Super::OnPossess(InPawn);
	if (bBoard)
	{
		bBoard->InitializeBlackboard(*bTree->BlackboardAsset);
	}
}

void AController_AI::OnAttacked()
{
	bBoard->SetValueAsBool(bb_keys::CanSeePlayer, true);
}

void AController_AI::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	if (!bCanMove)
	{
		StopMovement();
	}

}

UBlackboardComponent* AController_AI::get_blackboard() const
{
	return bBoard;
}

void AController_AI::SetCanMove(bool CanMove)
{
	bCanMove = CanMove;
}

void AController_AI::Disable()
{
	UE_LOG(LogTemp, Warning, L"Disable Called");
	BrainComponent->StopLogic("Disable");
	auto btComp = Cast<UBehaviorTreeComponent>(BrainComponent);
	if (btComp)
	{
		btComp->StopTree();
	}
	behaviorTreeComp->StopTree(EBTStopMode::Type::Safe);
	StopMovement();
}

void AController_AI::Enable()
{
	RunBehaviorTree(bTree);
	behaviorTreeComp->StartTree(*bTree);
	bBoard->SetValueAsBool(bb_keys::CanSeePlayer, false);
}



void AController_AI::on_target_detected(AActor* actor, FAIStimulus const stimulus)
{
	if (auto ch = Cast<ACharacter>(actor))
	{
		get_blackboard()->SetValueAsBool(bb_keys::CanSeePlayer, stimulus.WasSuccessfullySensed());
	}
}

void AController_AI::setup_perception_system()
{
	sight_config = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight Config"));
	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception Component")));
	sight_config->SightRadius = 1000.0f;
	sight_config->LoseSightRadius = sight_config->SightRadius + 50.0f;
	sight_config->PeripheralVisionAngleDegrees = 90.f;
	sight_config->SetMaxAge(5.0f);
	sight_config->AutoSuccessRangeFromLastSeenLocation = 900.f;
	sight_config->DetectionByAffiliation.bDetectEnemies = true;
	sight_config->DetectionByAffiliation.bDetectFriendlies = true;
	sight_config->DetectionByAffiliation.bDetectNeutrals = true;

	GetPerceptionComponent()->SetDominantSense(*sight_config->GetSenseImplementation());
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AController_AI::on_target_detected);
	GetPerceptionComponent()->ConfigureSense(*sight_config);

}
