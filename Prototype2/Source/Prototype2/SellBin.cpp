// Fill out your copyright notice in the Description page of Project Settings.


#include "SellBin.h"

#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Plant.h"
#include "Prototype2Character.h"
#include "Prototype2PlayerState.h"
#include "Particles/ParticleSystem.h"
#include "GameFramework/PlayerState.h"
#include "Components/WidgetComponent.h"
#include "Widgets/Widget_SellCropUI.h"

// Sets default values
ASellBin::ASellBin()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemComponent = CreateDefaultSubobject<UItemComponent>(TEXT("ItemComponent"));

	SellAmountWidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("SellAmountWidgetComponent"));
	//SellAmountWidgetComponent->SetupAttachment(ItemComponent->Mesh);
	startPositionZ = SellAmountWidgetComponent->GetComponentTransform().GetLocation().Z;

	InterfaceType = EInterfaceType::SellBin;

	InteractSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Particle System"));
	InteractSystem->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ASellBin::BeginPlay()
{
	Super::BeginPlay();

	SellAmountWidgetComponent->SetupAttachment(ItemComponent->Mesh);
}

// Called every frame
void ASellBin::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASellBin::Server_FireParticleSystem_Implementation()
{
	//Multi_FireParticleSystem();
}

void ASellBin::Multi_FireParticleSystem_Implementation()
{
	// Spawn a one-shot emitter at the InteractSystem's location
	//UNiagaraComponent* NiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ParticleSystem, InteractSystem->GetComponentLocation());
	//NiagaraComponent->SetIsReplicated(true);
	//// Set the NiagaraComponent to auto-destroy itself after it finishes playing
	//NiagaraComponent->SetAutoDestroy(true);
	//NiagaraComponent->Activate();
}

void ASellBin::Interact(APrototype2Character* player)
{
	if (player->HeldItem)
	{
		if (auto* plant = Cast<APlant>(player->HeldItem))
		{
			Cast<APrototype2PlayerState>(player->GetPlayerState())->Coins += plant->ItemComponent->CropValue;
			player->HeldItem->Destroy();
			player->HeldItem = nullptr;
			
			//Server_FireParticleSystem();

			// Selling UI
			if (SellAmountWidgetComponent->GetWidget())
			{
				if (auto* SellCropUI = Cast<UWidget_SellCropUI>(SellAmountWidgetComponent->GetWidget()))
				{
					SellCropUI->SetCropValue(plant->ItemComponent->CropValue);
				}
			}
		}
	}
}

void ASellBin::OnDisplayInteractText(class UWidget_PlayerHUD* _invokingWiget, class APrototype2Character* owner, int _playerID)
{
	if(auto heldItem = owner->HeldItem)
	{
		if (heldItem->ItemComponent->PickupType == EPickup::Cabbage ||
			heldItem->ItemComponent->PickupType == EPickup::Carrot ||
			heldItem->ItemComponent->PickupType == EPickup::Mandrake)
		{
			_invokingWiget->SetHUDInteractText("Sell");
		}
	}
}

