// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponSeed.h"

AWeaponSeed::AWeaponSeed()
{
	bReplicates = true;

	InterfaceType = EInterfaceType::Default;

	PrimaryActorTick.bCanEverTick = true;
}

void AWeaponSeed::BeginPlay()
{
	Super::BeginPlay();
}

void AWeaponSeed::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
}
