// Fill out your copyright notice in the Description page of Project Settings.


#include "EndGamePodium.h"
#include "Components/ArrowComponent.h"

// Sets default values
AEndGamePodium::AEndGamePodium()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	
	ThirdPlaceMeshes.Emplace(CreateDefaultSubobject<UStaticMeshComponent>(FName("Third Place Mesh")));
	RootComponent = ThirdPlaceMeshes[0];
	
	for(int i = 0; i < 3; i++)
	{
		FirstPlaceMeshes.Emplace(CreateDefaultSubobject<UStaticMeshComponent>(FName("First Place Mesh" / FString::FromInt(i))));
		FirstPlaceMeshes[i]->SetupAttachment(ThirdPlaceMeshes[0]);
	}
	for(int i = 0; i < 2; i++)
	{
		SecondPlaceMeshes.Emplace(CreateDefaultSubobject<UStaticMeshComponent>(FName("Second Place Mesh" / FString::FromInt(i))));
		SecondPlaceMeshes[i]->SetupAttachment(ThirdPlaceMeshes[0]);
	}

	P1Position = CreateDefaultSubobject<UArrowComponent>(FName("P1 Spawn Pos"));
	P1Position->SetupAttachment(RootComponent);
	P2Position = CreateDefaultSubobject<UArrowComponent>(FName("P2 Spawn Pos"));
	P2Position->SetupAttachment(RootComponent);
	P3Position = CreateDefaultSubobject<UArrowComponent>(FName("P3 Spawn Pos"));
	P3Position->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AEndGamePodium::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEndGamePodium::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

