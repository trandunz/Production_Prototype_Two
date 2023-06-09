// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "IndexTypes.h"
#include "GameFramework/Actor.h"
#include "RaidialSpawner.generated.h"

UCLASS()
class PROTOTYPE2_API ARaidialSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARaidialSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnywhere)
	bool changePlayerCount = true;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ARadialPlot> PlotPrefab;

	UPROPERTY(EditAnywhere)
	class USceneComponent* InitialSpawn;

	UPROPERTY(EditAnywhere)
	int playercount = 12;

	void SetUp();

	UPROPERTY()
	TMap<int32, ARadialPlot*> Plots;
	
	UFUNCTION(BlueprintCallable)
	void SetupDelayed();
};
