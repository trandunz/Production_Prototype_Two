// Fill out your copyright notice in the Description page of Project Settings.


#include "Seed.h"

#include "Prototype2Character.h"

ASeed::ASeed()
{
	// make sure to rep
	bReplicates = true;

	InterfaceType = EInterfaceType::Default;

	ParachuteMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Parachute"));
	ParachuteMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	PrimaryActorTick.bCanEverTick = true;
}

void ASeed::BeginPlay()
{
	Super::BeginPlay();
	ParachuteMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	ParachuteMesh->SetRelativeLocation(ParachuteMesh->GetRelativeLocation() + (FVector::UpVector * 100));
	ParachuteMesh->SetRelativeScale3D({2,2,2});
	ParachuteMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	if (!isWeapon)
	{
		SpawnPos = GetActorLocation();
		SpawnRotation = GetActorRotation();
		SpawnTime = GetWorld()->GetTimeSeconds();
		ItemComponent->Mesh->SetSimulatePhysics(false);
	}
	SetReplicates(true);
	SetReplicatingMovement(true);
}

void ASeed::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	HandleParachuteMovement();
}

void ASeed::Interact(APrototype2Character* player)
{
	ItemComponent->Interact(player, this);
	
	player->EnableStencil(false);
	if (player->PlayerHUDRef)
	{
		player->PlayerHUDRef->SetHUDInteractText("");
	}
	ItemComponent->Mesh->SetRenderCustomDepth(false);
}

void ASeed::ClientInteract(APrototype2Character* player)
{
	IInteractInterface::ClientInteract(player);

	player->UpdateDecalDirection(true, false);
}

void ASeed::OnDisplayInteractText(class UWidget_PlayerHUD* _invokingWiget, class APrototype2Character* owner, int _playerID)
{
	if (!owner->HeldItem || owner->HeldItem != this)
	{
		_invokingWiget->SetHUDInteractText("Pick Up");

		owner->EnableStencil(true);
	}
}

bool ASeed::IsInteractable(APrototype2PlayerState* player)
{
	return true;
}

void ASeed::HandleParachuteMovement()
{
	if (!isWeapon)
	{
		if (HasAuthority() || GetLocalRole() == ROLE_AutonomousProxy)
		{
			if (GetActorLocation().Z - 1.0f >= (SpawnPos + (FVector::DownVector * DropDistance)).Z)
			{
				float xVariation = FMath::Sin(FMath::DegreesToRadians(GetWorld()->GetTimeSeconds()) * BobSpeed) * BobAmplitude;
				float zVariation = FMath::Cos(FMath::DegreesToRadians(GetWorld()->GetTimeSeconds()) * BobSpeed ) * BobAmplitude;
				SetActorRotation({SpawnRotation.Pitch + xVariation, GetActorRotation().Yaw, SpawnRotation.Roll + zVariation});
				float lifetime = GetWorld()->GetTimeSeconds() - SpawnTime;
				SetActorLocation(FMath::Lerp(SpawnPos, SpawnPos + (FVector::DownVector * DropDistance), lifetime / FallTime), false, nullptr, ETeleportType::ResetPhysics);
			}
			else
			{
				ItemComponent->Mesh->SetSimulatePhysics(true);
				ParachuteMesh->SetVisibility(false);
			}
		}
	}
}

void ASeed::Grow()
{
}
