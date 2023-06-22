// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InteractInterface.h"
#include "ItemComponent.h"
#include "NiagaraComponent.h"
#include "GrowSpot.generated.h"

class APlant;
class AGrowableWeapon;
class ASeed;
class AWeaponSeed;
UCLASS()
class PROTOTYPE2_API AGrowSpot : public AActor, public IInteractInterface
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrowSpot();

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	virtual bool IsInteractable(APrototype2PlayerState* player) override;
	UPROPERTY(Replicated, EditAnywhere)
	int Player_ID = 0;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UFUNCTION(NetMulticast, Reliable)
	void Multi_Plant();
	void Multi_Plant_Implementation();

	UFUNCTION(NetMulticast, Reliable)
	void Multi_FireParticleSystem();
	void Multi_FireParticleSystem_Implementation();

	void GrowPlantOnTick(float DeltaTime);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(NetMulticast, Reliable)
	void Multi_GrowOnTick(float _deltaTime);
	void Multi_GrowOnTick_Implementation(float _deltaTime);

	UFUNCTION(NetMulticast, Reliable)
	void Multi_UpdateState(EGrowSpotState _newState);
	void Multi_UpdateState_Implementation(EGrowSpotState _newState);

	UFUNCTION(NetMulticast, Reliable)
	void Multi_SetPlantReadySparkle(bool _bIsActive);
	void Multi_SetPlantReadySparkle_Implementation(bool _bIsActive);
	
	UPROPERTY(EditAnywhere)
	UItemComponent* ItemComponent;

	virtual void Interact(APrototype2Character* player) override;
	virtual void OnDisplayInteractText(class UWidget_PlayerHUD* _invokingWiget, class APrototype2Character* owner, int _playerID) override;

	void SetPlant(APlant* _plant, float _growTime);
	void SetWeapon(AGrowableWeapon* _weapon, float _growTime);

	UPROPERTY(Replicated, VisibleAnywhere)
	EGrowSpotState GrowSpotState = EGrowSpotState::Empty;

	UPROPERTY(Replicated, VisibleAnywhere)
	APlant* plant = nullptr;
	UPROPERTY(Replicated, VisibleAnywhere)
	AGrowableWeapon* weapon = nullptr;

	UPROPERTY(Replicated, VisibleAnywhere)
	float growTimer{};
	
	UPROPERTY(Replicated, EditAnywhere)
	float growTime{10};

	UPROPERTY(EditAnywhere)
	class UNiagaraSystem* ParticleSystem;

	UPROPERTY(EditAnywhere)
	class UNiagaraComponent* InteractSystem;

	UPROPERTY(EditAnywhere)
	USoundAttenuation* MandrakeAttenuationSettings;

	// Plant ready sparkle VFX
	UPROPERTY(Replicated, EditAnywhere, Category = VFX)
	class UNiagaraSystem* PlantReadySparkle_NiagaraSystem;
	UPROPERTY(Replicated, BlueprintReadWrite, EditAnywhere, Category = VFX)
	class UNiagaraComponent* PlantReadySparkle_NiagaraComponent;
};

