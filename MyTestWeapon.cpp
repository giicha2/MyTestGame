// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestWeapon.h"
#include "Components/BoxComponent.h"


// Sets default values
AMyTestWeapon::AMyTestWeapon(const class FObjectInitializer& ObjectInitializer):Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	WeaponMesh = ObjectInitializer.CreateDefaultSubobject<USkeletalMeshComponent>(this, TEXT("WeaponMesh"));
	WeaponMesh->CastShadow = true;
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent=WeaponMesh;

	WeaponCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("WeaponCollision"));
	WeaponCollision->SetBoxExtent(FVector(5.f, 5.f, 5.f));
	WeaponCollision->AttachTo(WeaponMesh, "DamageSocket");

}

 

void AMyTestWeapon::SetOwningPawn(AMyBasicCharacter* NewOwner)
{
	if (MyPawn != NewOwner)
	{
		MyPawn = NewOwner;
	}
}



void AMyTestWeapon::AttachMeshToPawn()
{
	if (MyPawn)
	{
		USkeletalMeshComponent* PawnMesh = MyPawn->GetSpesificPawnMesh();
		FName AttachPoint = MyPawn->GetWeaponAttachPoint();
		WeaponMesh->AttachTo(PawnMesh, AttachPoint);
	}

}

void AMyTestWeapon::OnEquip(const AMyTestWeapon* LastWeapon)
{
	AttachMeshToPawn();
}

// Called when the game starts or when spawned
void AMyTestWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTestWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

