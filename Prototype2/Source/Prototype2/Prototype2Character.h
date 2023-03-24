// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "Prototype2Character.generated.h"

class UAudioComponent;
class USoundCue;
class UItemComponent;

UCLASS(config=Game)
class APrototype2Character : public ACharacter
{
	GENERATED_BODY()
public:
	APrototype2Character();	

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	
	UPROPERTY(VisibleAnywhere, Replicated)
	int PlayerID{-1};
public: // Public Networking functions
	UFUNCTION(Server, Reliable)
	void Server_PickupItem(UItemComponent* itemComponent, APickUpItem* _item);
	void Server_PickupItem_Implementation(UItemComponent* itemComponent, APickUpItem* _item);

	UFUNCTION(Server, Reliable)
	void Server_SocketItem(UStaticMeshComponent* _object, FName _socket);
	void Server_SocketItem_Implementation(UStaticMeshComponent* _object, FName _socket);

	UFUNCTION(Server, Reliable)
	void Server_DropItem();
	void Server_DropItem_Implementation();
	
	UFUNCTION(Server, Reliable)
	void Server_AddHUD();
	void Server_AddHUD_Implementation();

	UFUNCTION(NetMulticast, Reliable)
	void Multi_Client_AddHUD();
	void Multi_Client_AddHUD_Implementation();

	UFUNCTION(Server, Reliable)
	void Server_StartAttack();
	void Server_StartAttack_Implementation();
	UFUNCTION(NetMulticast, Reliable)
	void Multi_StartAttack();
	void Multi_StartAttack_Implementation();
	
	UFUNCTION(Server, Reliable)
	void Server_ReleaseAttack();
	void Server_ReleaseAttack_Implementation();
	UFUNCTION(NetMulticast, Reliable)
	void Multi_ReleaseAttack();
	void Multi_ReleaseAttack_Implementation();

	UFUNCTION(Server, Reliable)
	void Server_PlaySoundAtLocation(FVector _location, USoundCue* _soundQueue);
	void Server_PlaySoundAtLocation_Implementation(FVector _location, USoundCue* _soundQueue);
	UFUNCTION(NetMulticast, Reliable)
	void Multi_PlaySoundAtLocation(FVector _location, USoundCue* _soundQueue);
	void Multi_PlaySoundAtLocation_Implementation(FVector _location, USoundCue* _soundQueue);
	
	UFUNCTION(Client, Reliable)
	void Client_AddHUD();
	void Client_AddHUD_Implementation();
	
	UPROPERTY(VisibleAnywhere, Replicated)
	UMaterialInstance* PlayerMat;

	UPROPERTY(EditAnywhere, Replicated)
	USoundAttenuation* SoundAttenuationSettings;
protected: // Protected Networking functions
	void PlayNetworkMontage(UAnimMontage* _montage);
	
	UFUNCTION(Server, Reliable)
	void Server_PlayNetworkMontage(UAnimMontage* _montage);
	void Server_PlayNetworkMontage_Implementation(UAnimMontage* _montage);
	
	UFUNCTION(NetMulticast, Reliable)
	void Multi_PlayNetworkMontage(UAnimMontage* _montage);
	void Multi_PlayNetworkMontage_Implementation(UAnimMontage* _montage);

	UFUNCTION(Server, Reliable)
	void Server_SetPlayerColour();
	void Server_SetPlayerColour_Implementation();
	
	UFUNCTION(NetMulticast, Reliable)
	void Multi_SetPlayerColour();
	void Multi_SetPlayerColour_Implementation();
	
	UFUNCTION(Server, Reliable)
	void Server_TryInteract();
	void Server_TryInteract_Implementation();

	UFUNCTION(NetMulticast, Reliable)
	void Multi_DropItem();
	void Multi_DropItem_Implementation();
	
	UFUNCTION(NetMulticast, Reliable)
	void Multi_PickupItem(UItemComponent* itemComponent, APickUpItem* _item);
	void Multi_PickupItem_Implementation(UItemComponent* itemComponent, APickUpItem* _item);

	UFUNCTION(NetMulticast, Reliable)
	void Multi_SocketItem(UStaticMeshComponent* _object, FName _socket);
	void Multi_SocketItem_Implementation(UStaticMeshComponent* _object, FName _socket);


protected: // Protected Functions
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	virtual void BeginPlay();

	virtual void Tick(float DeltaSeconds) override;
	
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/* Called for Attack input */
	void ChargeAttack();

	/* Release Attack */
	void ReleaseAttack();

	/* Execute Attack */
	void ExecuteAttack(float AttackSphereRadius);

	/* Pickup/Plant/Sell */
	void Interact();

	/* Create a sphere collider which calculates nearest item */
	void CheckForInteractables();

	/* Called when hit by another player */
	UFUNCTION(BlueprintCallable)
	void GetHit(float AttackCharge, FVector AttackerLocation);
	
	/* UI */
	void OpenIngameMenu();
	
	void UpdateAllPlayerIDs();

	UFUNCTION(Server, Reliable)
	void Server_ReceiveMaterialsArray(const TArray<UMaterialInstance*>& InMaterialsArray);
	void Server_ReceiveMaterialsArray_Implementation(const TArray<UMaterialInstance*>& InMaterialsArray);
	UFUNCTION(NetMulticast, Reliable)
	void Multi_ReceiveMaterialsArray(const TArray<UMaterialInstance*>& InMaterialsArray);
	void Multi_ReceiveMaterialsArray_Implementation(const TArray<UMaterialInstance*>& InMaterialsArray);

	ENetRole IdealNetRole{ROLE_AutonomousProxy};



private: // Input actions
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

	/* UI */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MenuAction;

	/* Attack */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ChargeAttackAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* ReleaseAttackAction;

	/* PickUp/Plant/Sell */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* InteractAction;

private: // Animation
	UPROPERTY(EditAnywhere)
	class UAnimMontage* PickupMontage;
	
	UPROPERTY(EditAnywhere)
	class UAnimMontage* ExecuteAttackMontage;
private: // Private variables

	/* Interact radius for checking closest item */
	UPROPERTY(EditAnywhere)
	float InteractRadius = 200.0f;

	/* Maximum amount of Attack Charge */
	UPROPERTY(EditAnywhere)
	float MaxAttackCharge = 3.0f;

	/* Amount of knockback applied which is multiplied by charge */
	UPROPERTY(EditAnywhere)
	float KnockBackAmount = 1000.0f;

	/* Interact timer */
	UPROPERTY(EditAnywhere)
	float InteractTimerTime = 1.0f;
	float InteractTimer{};
	
	/* Attack timer */
	UPROPERTY(EditAnywhere)
	float AttackTimerTime = 1.0f;
	float AttackTimer{};
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class UWidget_PlayerHUD> PlayerHudPrefab;
	UWidget_PlayerHUD* PlayerHUDRef;

public: // audio
	void PlaySoundAtLocation(FVector Location, USoundCue* SoundToPlay);

	void Ragdoll(bool _ragdoll);
	UFUNCTION(Server, Reliable)
	void Server_Ragdoll(bool _ragdoll);
	void Server_Ragdoll_Implementation(bool _ragdoll);
	UFUNCTION(NetMulticast, Reliable)
    void Multi_Ragdoll(bool _ragdoll);
    void Multi_Ragdoll_Implementation(bool _ragdoll);
	
	UAudioComponent* ChargeAttackAudioComponent;

	UPROPERTY(EditAnywhere)
	USoundCue* ChargeCue;
	UPROPERTY(EditAnywhere)
	USoundCue* ExecuteCue;
	UPROPERTY(EditAnywhere)
	USoundCue* PickUpCue;
	UPROPERTY(EditAnywhere)
	USoundCue* DropCue;
	UPROPERTY(EditAnywhere)
	USoundCue* SellCue;
	UPROPERTY(EditAnywhere)
	USoundCue* PlantCue;
	UPROPERTY(EditAnywhere)
	USoundCue* GetHitCue;
	UPROPERTY(EditAnywhere)
	USoundCue* MandrakeScreamCue;
	
public:
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class UWeapon* Weapon;
	
	/* Currently held item */
	UPROPERTY(Replicated, EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	class APickUpItem* HeldItem;

	/* Is player holding down attack */
	UPROPERTY(Replicated, BlueprintReadOnly)
	bool bIsChargingAttack;

	class IInteractInterface* ClosestInteractableItem;
	
protected:
	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;


private:
	UPROPERTY(Replicated)
	float AttackChargeAmount;
	UPROPERTY(Replicated)
	bool bIsStunned;
	UPROPERTY(Replicated)
	float StunTimer;
	bool DoOnce{};

	UPROPERTY(Replicated, VisibleAnywhere)
	FTransform LocationWhenStunned{};
	UPROPERTY(Replicated, VisibleAnywhere)
	FTransform MeshLocationWhenStunned{};
};
