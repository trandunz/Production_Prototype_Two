// Fill out your copyright notice in the Description page of Project Settings.


#include "GrowSpot.h"
#include "Plant.h"
#include "Prototype2Character.h"
#include "Prototype2PlayerState.h"
#include "Seed.h"
#include "WeaponSeed.h"

// Sets default values
AGrowSpot::AGrowSpot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemComponent = CreateDefaultSubobject<UItemComponent>(TEXT("ItemComponent"));
	bReplicates = true;
}

// Called when the game starts or when spawned
void AGrowSpot::BeginPlay()
{
	Super::BeginPlay();

	InterfaceType = EInterfaceType::GrowSpot;
	ItemComponent->Mesh->SetCollisionProfileName("OverlapAll");
}

void AGrowSpot::Multi_Plant_Implementation()
{
	if (plant)
	{
		if (plant->ItemComponent)
		{
			if (plant->ItemComponent->Mesh)
			{
				plant->ItemComponent->Mesh->SetSimulatePhysics(false);
				plant->ItemComponent->Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			}
		}
	}
}

// Called every frame
void AGrowSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (growingPlant)
	{
		if (growTime > 0)
			growTime -= DeltaTime;
		if (growTime <= 0)
		{
			plantGrown = true;
			growingPlant = false;
		}
	}
}

void AGrowSpot::Interact(APrototype2Character* player)
{
	if (auto* playerState = player->GetPlayerState<APrototype2PlayerState>())
	{
		if (playerState->Player_ID == Player_ID)
		{
			if (auto* weaponSeed = Cast<AWeaponSeed>(player->HeldItem))
			{
				if (!plant && !weapon)
				{
					//SetWeapon(weaponSeed->weaponToGrow, weaponSeed->growtime);
				}
			}
			else if (auto* seed = Cast<ASeed>(player->HeldItem))
			{
				if (!plant && !weapon)
				{
					if (seed->plantToGrow)
					{
						auto* newPlant = GetWorld()->SpawnActor(seed->plantToGrow);
						SetPlant(Cast<APlant>(newPlant), seed->growtime);
						plant->SetActorLocation(GetActorLocation());
						Multi_Plant();
						if (seed)
							seed->Destroy();
					}
				}
			}
			else if (plant)
			{
				if (plantGrown)
				{
					player->HeldItem = plant;
					player->Server_PickupItem(plant->ItemComponent, plant);
					plant->isGrown = true;
					plant = nullptr;
					plantGrown = false;
					//enable physics
				}
			}
		}
	}
	
	//else if (weapon)
	//{
	//	if (plantGrown)
	//	{
	//		player->Weapon = weapon;
	//		weapon = nullptr;
	//		plantGrown = false;
	//	}
	//}
}

void AGrowSpot::SetPlant(APlant* _plant, float _growTime)
{
	if (!plant)
	{
		plant = _plant;
		growTime = _growTime;
		growingPlant = true;
	}
}

void AGrowSpot::SetWeapon(AWeapon* _weapon, float _growTime)
{
	if (!weapon)
	{
		weapon = _weapon;
		growTime = _growTime;
		growingPlant = true;
	}
}

