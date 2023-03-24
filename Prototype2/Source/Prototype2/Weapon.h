// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickUpItem.h"
#include "Weapon.generated.h"

UCLASS()
class PROTOTYPE2_API UWeapon : public UActorComponent, public IInteractInterface
{
	GENERATED_BODY()
	//UPROPERTY(EditAnywhere)
	//int numberOfHits; replaced with ItemComponent->Durability

public:
	virtual void Interact(APrototype2Character* player) override;
	virtual void OnDisplayInteractText(class UWidget_PlayerHUD* _invokingWiget, class APrototype2Character* owner, int _playerID) override;
//private:
	UWeapon();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess))
	class UStaticMeshComponent* Mesh;

private:

};
