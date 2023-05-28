// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUpItem.h"
#include "Plant.generated.h"

UCLASS()
class PROTOTYPE2_API APlant : public APickUpItem, public IInteractInterface
{
	GENERATED_BODY()
public:
	APlant();
	virtual void BeginPlay() override;
	virtual void Interact(APrototype2Character* player) override;
	virtual void OnDisplayInteractText(class UWidget_PlayerHUD* _invokingWiget, class APrototype2Character* owner, int _playerID) override;
	bool isGrown = false;
	UPROPERTY(EditAnywhere)
	// ReSharper disable once CppUE4ProbableMemoryIssuesWithUObject
	UMaterialInterface* goldMaterial;
	UPROPERTY(EditAnywhere)
	// ReSharper disable once CppUE4ProbableMemoryIssuesWithUObject
	UMaterialInterface* goldMaterial2;
	
	int chanceOfGold = 5; // x/100
	int goldMultiplier = 3;
	//UPROPERTY(EditAnywhere)
	//float value; // Moved to ItemComponent
	
};
