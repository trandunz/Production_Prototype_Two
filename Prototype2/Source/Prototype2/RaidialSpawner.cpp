// Fill out your copyright notice in the Description page of Project Settings.


#include "RaidialSpawner.h"
#include "RadialPlot.h"
#include "Gamestates/Prototype2Gamestate.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
ARaidialSpawner::ARaidialSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARaidialSpawner::BeginPlay()
{
	Super::BeginPlay();

	if (PlotPrefab)
		SetUp();
}

void ARaidialSpawner::SetUp()
{
	if (auto gamestate = Cast<APrototype2Gamestate>(UGameplayStatics::GetGameState(GetWorld())))
	{
		if (changePlayerCount)
		{
			playercount = gamestate->FinalConnectionCount;
		}
	}
	if (playercount <= 0)
	{
		playercount = UGameplayStatics::GetGameMode(GetWorld())->GetNumPlayers();
	}
	if (playercount <= 0)
	{
		return;
	}
	
	float SpawnRadius = 3000;

	float AngleStep = 360.0f / playercount; // Calculate the angle between each object

	for (int32 Index = 0; Index < playercount; Index++)
	{
		// Calculate the angle for the current object
		float Angle = Index * AngleStep;

		// Convert angle to radians
		float Radians = FMath::DegreesToRadians(Angle);

		// Calculate the spawn position offset based on angle and radius
		float OffsetX = SpawnRadius * FMath::Cos(Radians);
		float OffsetY = SpawnRadius * FMath::Sin(Radians);
		
		FVector ObjectSpawnPosition = GetActorLocation() + FVector(OffsetX, OffsetY, -1337.0f /*XD this value does nothing real one is in RadialPlot.cpp*/);

		// Spawn the object at the calculated position
		auto spawnedRadialPlot = GetWorld()->SpawnActor<ARadialPlot>(PlotPrefab, ObjectSpawnPosition, FRotator(0, Angle + 90, 0));
		
		if (spawnedRadialPlot)
		{
			spawnedRadialPlot->SetPlayerID(Index);
		}
	}
	
}

