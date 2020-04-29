// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "MyTestGameAIController.generated.h"

/**
 * 
 */
class UBehaviorTreeComponent;
class UBlackboardComponent;

UCLASS(config=Game)
class  AMyTestGameAIController : public AAIController
{
	GENERATED_BODY()

public:
	AMyTestGameAIController(FObjectInitializer const& object_intializer=FObjectInitializer::Get());

	virtual void BeginPlay() override;
	virtual void OnPossess(APawn* Pawn)override;
	virtual void Tick(float DeltaSeconds)override;
	virtual FRotator GetControlRotation()const override;

	UFUNCTION()
	void OnPawnDetected(const TArray<AActor*> &DetectedPawns);

	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category=AI)
	float AISightRadius = 500.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	float AISightAge = 5.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	float AILoseSightRadius = AISightRadius + 50.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	float AIFieldOfView = 90.f;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	class UAISenseConfig_Sight* SightConfig;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
	bool bIsPlayerDetected = false;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = AI)
		float DistanceToPlayer = 0.0f;


	class UBlackboradComponent* get_blackboard() const;

//private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPriveteAccess = "true"))
		class UBehaviorTreeComponent* behaviortree_Comp;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPriveteAccess = "true"))
		class UBehaviorTree* btree;


	class UBlackboardComponent* blackboard;
	


	//UPROPERTY(transient)
	//	UBlackboardComponent* BlackboardComp;

	//UPROPERTY(transient)
	//	UBehaviorTreeComponent* BehaviorComp;
};
