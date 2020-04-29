// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_RandomMove.h"
#include "MyTestGame.h"
#include "BehaviorTree/BTNode.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/Blackboard/BlackboardKeyAllTypes.h"
#include "NavigationSystem.h"
#include "MyTestGameAIController.h"
#include "Engine.h"
#include "Engine/World.h"

UBTTask_RandomMove::UBTTask_RandomMove(FObjectInitializer const& object_initializer)
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UBTTask_RandomMove::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	UNavigationSystemV1* const NavSys = UNavigationSystemV1::GetCurrent(GetWorld());

	AMyTestGameAIController* MyController = Cast<AMyTestGameAIController>(OwnerComp.GetAIOwner());

	if (NavSys && MyController && MyController->GetPawn())
	{
		const float SearchRadius = 200.0f;
		FNavLocation RandomPt;

		const bool bFound = NavSys->GetRandomPointInNavigableRadius(MyController->GetPawn()->GetActorLocation(), SearchRadius, RandomPt);

		if (bFound)
		{
			OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Vector>(GetSelectedBlackboardKey(), RandomPt.Location);

			return EBTNodeResult::Succeeded;
		}
	}
	return EBTNodeResult::Failed;
}

