// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "ItemComponent.h"
#include "GrowSpot.generated.h"

class APlant;
class AWeapon;
class ASeed;
class AWeaponSeed;
UCLASS()
class PROTOTYPE2_API AGrowSpot : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrowSpot();

	UPROPERTY(EditAnywhere)
	int Player_ID = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(NetMulticast, Reliable)
	void Multi_Plant();
	void Multi_Plant_Implementation();

	void GrowPlantOnTick(float DeltaTime);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UItemComponent* ItemComponent;

	virtual void Interact(APrototype2Character* player) override;

	void SetPlant(APlant* _plant, float _growTime);
	void SetWeapon(AWeapon* _weapon, float _growTime);
	
	APlant* plant = nullptr;
	AWeapon* weapon = nullptr;

	float growTimer{};
	UPROPERTY(EditAnywhere)

	float growTime{10};
	
	bool growingPlant = false;
	bool plantGrown = false;
};
