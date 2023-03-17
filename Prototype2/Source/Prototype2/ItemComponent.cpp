﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemComponent.h"
#include "Prototype2Character.h"
#include "PickUpItem.h"


// Sets default values for this component's properties
UItemComponent::UItemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ItemMesh"));
	if(GetOwner())
	{
		GetOwner()->SetRootComponent(Mesh);
	}
}

// Called when the game starts
void UItemComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// Setup Collisions and physics
	Mesh->SetCollisionProfileName("Ragdoll");
	Mesh->SetCollisionResponseToChannel(ECC_Camera, ECR_Ignore);
	Mesh->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	Mesh->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	Mesh->SetSimulatePhysics(true);
}

// Called every frame
void UItemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UItemComponent::Interact(APrototype2Character* player, APickUpItem* itemPickedUp)
{
	// Setup Mesh
	Mesh->SetSimulatePhysics(false);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// Set players HeldItem
	player->HeldItem = itemPickedUp;
	
	// Attach to socket
	itemPickedUp->AttachToComponent(player->GetMesh(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("HeldItemSocket"))
	
	// Assign Players HeldItem
	player->HeldItem = itemPickedUp;

	// Debug
	UE_LOG(LogTemp, Warning, TEXT("HeldItem attached to hand"));	
}

