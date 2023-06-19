// Fill out your copyright notice in the Description page of Project Settings.


#include "GrowSpot.h"
#include "GrowSpot.h"
#include "Plant.h"
#include "Prototype2Character.h"
#include "Prototype2PlayerState.h"
#include "Seed.h"
#include "GrowableWeapon.h"
#include "Net/UnrealNetwork.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "Weapon.h"

// Sets default values
AGrowSpot::AGrowSpot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ItemComponent = CreateDefaultSubobject<UItemComponent>(TEXT("ItemComponent"));
	bReplicates = true;

	InteractSystem = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Particle System"));
	InteractSystem->SetupAttachment(RootComponent);

	InterfaceType = EInterfaceType::GrowSpot;
}

void AGrowSpot::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(AGrowSpot, growTimer);
	DOREPLIFETIME(AGrowSpot, growTime);
	DOREPLIFETIME(AGrowSpot, growingPlant);
	DOREPLIFETIME(AGrowSpot, plantGrown);
	DOREPLIFETIME(AGrowSpot, plant);
	DOREPLIFETIME(AGrowSpot, weapon);
	DOREPLIFETIME(AGrowSpot, GrowSpotState);
}

// Called when the game starts or when spawned
void AGrowSpot::BeginPlay()
{
	Super::BeginPlay();

	InterfaceType = EInterfaceType::GrowSpot;
	GrowSpotState = EGrowSpotState::Empty;

	ItemComponent->Mesh->SetCollisionProfileName("OverlapAll");

	if (ParticleSystem)
	{
		InteractSystem->SetAsset(ParticleSystem);
	}
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
	if (weapon)
	{
		if (weapon->ItemComponent)
		{
			if (weapon->ItemComponent->Mesh)
			{
				weapon->ItemComponent->Mesh->SetSimulatePhysics(false);
				weapon->ItemComponent->Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			}
		}
	}
}

void AGrowSpot::Multi_FireParticleSystem_Implementation()
{
	// Spawn a one-shot emitter at the InteractSystem's location
	UNiagaraComponent* NiagaraComponent = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ParticleSystem, InteractSystem->GetComponentLocation());
	NiagaraComponent->SetIsReplicated(true);
	// Set the NiagaraComponent to auto-destroy itself after it finishes playing
	NiagaraComponent->SetAutoDestroy(true);
}

void AGrowSpot::GrowPlantOnTick(float _deltaTime)
{
	if (growTimer > 0 && HasAuthority())
	{
		growTimer -= _deltaTime;
	}
}

// Called every frame
void AGrowSpot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (plant)
	{
		FVector scale = FMath::Lerp<FVector>({2.0f, 2.0f, 2.0f}, {0.1f, 0.1f, 0.1f}, growTimer / growTime);
		FVector pos = FMath::Lerp<FVector>({GetActorLocation()}, GetActorLocation() + FVector::UpVector * 10.0f, growTimer / growTime);
		ItemComponent->Mesh->SetCollisionProfileName("OverlapAll");
		plant->ItemComponent->Mesh->SetSimulatePhysics(false);
		plant->ItemComponent->Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		plant->ItemComponent->Mesh->SetWorldScale3D(scale);
		plant->SetActorLocation(pos);
		plant->SetActorRotation(FRotator(0,0,0));
	}
	
	if (weapon)
	{
		FVector scale = FMath::Lerp<FVector>({2.0f, 2.0f, 2.0f}, {0.1f, 0.1f, 0.1f}, growTimer / growTime);
		FVector pos = FMath::Lerp<FVector>({GetActorLocation()}, GetActorLocation() + FVector::UpVector * 10.0f, growTimer / growTime);
		ItemComponent->Mesh->SetCollisionProfileName("OverlapAll");
		weapon->ItemComponent->Mesh->SetSimulatePhysics(false);
		weapon->ItemComponent->Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		weapon->ItemComponent->Mesh->SetWorldScale3D(scale);
		weapon->SetActorLocation(pos);
		weapon->SetActorRotation(FRotator(0,0,0));
	}
	
	GrowPlantOnTick(DeltaTime);

	switch(GrowSpotState)
	{
	case EGrowSpotState::Growing:
		{
			InteractSystem->Deactivate();
			if (plant)
				plant->ItemComponent->Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
			ItemComponent->Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
			if (growTimer <= 0)
			{
				Multi_FireParticleSystem();
	
				// deprecated soon
				plantGrown = true; 
				growingPlant = false;
				//
					
				GrowSpotState = EGrowSpotState::Grown;
				InteractSystem->ResetSystem();
			}
			break;
		}
	case EGrowSpotState::Grown:
		{
			InteractSystem->Activate();
			if (plant)
			{
				plant->ItemComponent->Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				plant->ItemComponent->Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
			}
			if (weapon)
			{
				weapon->ItemComponent->Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
				weapon->ItemComponent->Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Ignore);
			}
	
			// not too sure about this stuff
			ItemComponent->Mesh->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
			ItemComponent->Mesh->SetCollisionProfileName("OverlapAll");
			//
			break;
		}
	default:
		break;
	}
}

void AGrowSpot::Interact(APrototype2Character* player)
{
	if (auto playerState = player->GetPlayerState<APrototype2PlayerState>())
	{
		if (playerState->Player_ID == Player_ID)
		{
			if (auto seed = Cast<ASeed>(player->HeldItem))
			{
				switch(GrowSpotState)
				{
				case EGrowSpotState::Empty:
					{
						if (plant)
							break;
						// seed has an assigned plant
						if (seed->plantToGrow)
						{
							// Audio
							if (player->PlantCue)
							{
								player->PlaySoundAtLocation(GetActorLocation(), player->PlantCue);
							}
							// Set grow time
							
							if (seed->growtime > 0)
							{
								growTime = seed->growtime;
							}
							else if (seed->ItemComponent->GrowTime > 0)
							{
								// deprecated soon
								growTime = seed->ItemComponent->GrowTime;
							}
							else
							{
								growTime = 1.0f;
							}
							
							if (seed->isWeapon)
							{
								SetWeapon(GetWorld()->SpawnActor<AGrowableWeapon>(seed->plantToGrow), growTime);
							}
							else
							{
								SetPlant(GetWorld()->SpawnActor<APlant>(seed->plantToGrow), growTime);
							}
							
							Multi_Plant();
							
							player->Server_DropItem();
							
							if (seed)
								seed->Destroy();
						}
						
						break;
					}
				case EGrowSpotState::Growing:
					{
						break;
					}
				case EGrowSpotState::Grown:
					{
						if (player->HeldItem)
						{
							player->Server_DropItem();
							player->UpdateDecalDirection(true, true);
							player->HeldItem = nullptr;
							break;
						}

						if (weapon)
						{
							weapon->isGrown = true;
							
							player->Server_PickupItem(weapon->ItemComponent, weapon);
							player->WeaponCurrentDurability = player->WeaponMaxDurability;
					
							//// Change the weapon UI for this player
							//player->GetPlayerHUD()->UpdateWeaponUI(EPickup::Weapon);
								
							
							weapon->Destroy();
							weapon = nullptr;
							GrowSpotState = EGrowSpotState::Empty;
							break;
						}
						else if (plant)
						{
							plant->isGrown = true;
							
							// Put players weapon on back
							player->Multi_SocketItem_Implementation(player->Weapon->Mesh, FName("WeaponHolsterSocket"));
							player->Server_PickupItem(plant->ItemComponent, plant);
							player->UpdateDecalDirection(true, true);
					
							// Special sound for mandrake when picked up
							if (player->HeldItem)
							{
								if (player->HeldItem->ItemComponent->PickupType == EPickup::Mandrake)
								{
									if (player->MandrakeScreamCue)
									{
										if (MandrakeAttenuationSettings)
										{
											player->PlaySoundAtLocation(GetActorLocation(), player->MandrakeScreamCue, MandrakeAttenuationSettings);
										}
										else
										{
											player->PlaySoundAtLocation(GetActorLocation(), player->MandrakeScreamCue); 
										}
									}
								}
							}
							else
							{
								player->HeldItem = plant;
							}
							
						}
						plantGrown = false;
						growingPlant = false;
						growTimer = -1;
						GrowSpotState = EGrowSpotState::Empty;
						break;
					}
				default:
					break;
				}
			}
		}
	}
}

void AGrowSpot::OnDisplayInteractText(class UWidget_PlayerHUD* _invokingWiget, class APrototype2Character* owner, int _playerID)
{
	//UE_LOG(LogTemp, Warning, TEXT("PlayerID: %s"), *FString::FromInt(_playerID))
	//UE_LOG(LogTemp, Warning, TEXT("GrowSpotID: %s"), *FString::FromInt(Player_ID))

	if (auto playerState = owner->GetPlayerState<APrototype2PlayerState>())
	{
		if (playerState->Player_ID == _playerID)
		{
			switch (GrowSpotState)
			{
			case EGrowSpotState::Empty:
				{
					// Set to "Grow"
					if(owner->HeldItem && Cast<ASeed>(owner->HeldItem))
					{
						_invokingWiget->SetHUDInteractText("Grow");

						owner->EnableStencil(true);
					}
					break;
				}
			case EGrowSpotState::Growing:
				{
					_invokingWiget->SetHUDInteractText("");
					owner->EnableStencil(false);
					break;
				}
			case EGrowSpotState::Grown:
				{
					if (!owner->HeldItem)
					{
						// Set to "Grow"
						_invokingWiget->SetHUDInteractText("Pick Up");
					}
					owner->EnableStencil(true);
					break;
				}
			default:
				{
					break;
				}
			}						
		}
	}
}

void AGrowSpot::SetPlant(APlant* _plant, float _growTime)
{
	if (!plant && !weapon)
	{
		plant = _plant;
		growTimer = _growTime;
		GrowSpotState = EGrowSpotState::Growing;
		
		if (growTimer <= 0)
		{
			growTimer = 1.0f;
		}
	}
}

void AGrowSpot::SetWeapon(AGrowableWeapon* _weapon, float _growTime)
{
	if (!weapon && !plant)
	{
		weapon = _weapon;
		growTimer = _growTime;
		GrowSpotState = EGrowSpotState::Growing;
		
		if (growTimer <= 0)
		{
			growTimer = 1.0f;
		}
	}
}

