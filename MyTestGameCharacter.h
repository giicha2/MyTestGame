// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyBasicCharacter.h"
#include "MyTestGameCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MYTESTGAME_API AMyTestGameCharacter : public AMyBasicCharacter
{
	GENERATED_BODY()

public:
	AMyTestGameCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
		class UCameraComponent* FollowCamera;

	UPROPERTY(EditDefaultsOnly,Category=Pawn)
	UAnimMontage* Attack_Melee_AnimSet;

protected:
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)override;
	void MoveForward(float value);
	void MoveRight(float value);
	void Attack_Melee();
};
