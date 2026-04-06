// Fill out your copyright notice in the Description page of Project Settings.


#include "Inventory/Actor/Weapon/WeaponBase.h"

// Sets default values
AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>("Root");
	SetRootComponent(Root);
	SkeletalMesh= CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(Root);
	
}

void AWeaponBase::EndUseWeapon_Implementation()
{
}

void AWeaponBase::ReloadFirearm_Implementation()
{
}

void AWeaponBase::UseWeapon_Implementation()
{
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

