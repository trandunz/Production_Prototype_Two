#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SeedSpawner.generated.h"

class ASeed;
UCLASS()
class PROTOTYPE2_API ASeedSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ASeedSpawner();

protected:
	virtual void BeginPlay() override;

	void SpawnSeedsOnTick(float DeltaTime);

public:	
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere, Category = Seeds, meta = (AllowPrivateAccess))
	TArray<TSubclassOf<ASeed>> SeedPrefabs;
private:
	float SpawnTimer{};
	UPROPERTY(EditAnywhere, Category = Spawning, meta = (AllowPrivateAccess))
	int32 MaxSeedPackets{5};
	UPROPERTY(EditAnywhere, Category = Spawning, meta = (AllowPrivateAccess))
	float AverageSpawnTime{1.0f};
	UPROPERTY(EditAnywhere, Category = Spawning, meta = (AllowPrivateAccess))
	float MinSpawnRadius{100.0f};
	UPROPERTY(EditAnywhere, Category = Spawning, meta = (AllowPrivateAccess))
	float MaxSpawnRadius{800.0f};
};
