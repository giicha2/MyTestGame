// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "MyTestGameAIController.h"
#include "BTTask_FindPlayerLocation.generated.h"


/**
 * 
 */
UCLASS()
class MYTESTGAME_API UBTTask_FindPlayerLocation : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTTask_FindPlayerLocation(FObjectInitializer const& object_initializer);

	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AllowProtectedAccess = "true"))
		bool search_random = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Search", meta = (AllowProtectedAccess = "true"))
		float search_radius = 150.0f;
	
};
