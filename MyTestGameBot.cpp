// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestGameBot.h"
#include "GameFramework/CharacterMovementComponent.h"

AMyTestGameBot::AMyTestGameBot()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
}
