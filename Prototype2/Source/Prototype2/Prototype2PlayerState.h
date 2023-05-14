// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "Prototype2PlayerState.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE2_API APrototype2PlayerState : public APlayerState
{
	GENERATED_BODY()

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	APrototype2PlayerState();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaSeconds) override;
	
public:
	UPROPERTY(Replicated, VisibleAnywhere)
    int Player_ID{};
	
	UPROPERTY(Replicated, EditAnywhere)
	int Coins{0};

	// Showing coins that are being added to total
	UPROPERTY(Replicated, EditAnywhere)
	int ExtraCoins{0};
	UPROPERTY(Replicated, EditAnywhere)
	bool IsShowingExtraCoins{false};
	UPROPERTY(Replicated, EditAnywhere)
	float MaxTimeShowExtraCoins{};
	UPROPERTY(Replicated, VisibleAnywhere)
	float TimerExtraCoins{};


	
};
