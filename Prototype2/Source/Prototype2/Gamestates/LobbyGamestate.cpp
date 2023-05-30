#include "LobbyGamestate.h"

#include "Net/UnrealNetwork.h"
#include "Prototype2/LobbyPlayerState.h"
#include "Prototype2/Widgets/Widget_IngameMenu.h"
#include "Prototype2/Widgets/Widget_MapChoice.h"

ALobbyGamestate::ALobbyGamestate()
{
	PrimaryActorTick.bCanEverTick = true;
	bNetLoadOnClient = true;
}

void ALobbyGamestate::BeginPlay()
{
	Super::BeginPlay();
}

void ALobbyGamestate::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	if (HasAuthority())
	{
		
		if (PreviousServerTravel != ShouldServerTravel)
		{
			PreviousServerTravel = ShouldServerTravel;

			if (ShouldServerTravel)
			{
				if (LobbyLengthSeconds > 0 || LobbyLengthMinutes > 0)
				{
					IsCountingDown = true;
				}
				PreviousServerTravel = false;
				ShouldServerTravel = false;
			}
		}

		if (IsCountingDown)
		{
			if (LobbyLengthSeconds > 0)
			{
				LobbyLengthSeconds -= DeltaSeconds;
			}
			else
			{
				if (LobbyLengthMinutes <= 0)
				{
					// End of timer
					//GetWorld()->ServerTravel(MapChoice, false, false); // Start level

					// Show map choice
					bShowMapChoice = true;
					
					UE_LOG(LogTemp, Warning, TEXT("Farm: %d"), Farm);
					UE_LOG(LogTemp, Warning, TEXT("WinterFarm: %d"), WinterFarm);

					int totalVotes = Farm + WinterFarm;
					if (totalVotes == Server_Players.Num())
					{
						if (Farm > WinterFarm)
						{
							MapChoice = "Level_Main";
						}
						else if (WinterFarm > Farm)
						{
							MapChoice = "Level_Winter";
						}
						else
						{
							int randomNum = FMath::RandRange(0, 1);
							if (randomNum == 0)
							{
								MapChoice = "Level_Main";
							}
							else
							{
								MapChoice = "Level_Winter";
							}
						}
						GetWorld()->ServerTravel(MapChoice, false, false); // Start level
					}
				}
				else
				{
					LobbyLengthMinutes--;
					LobbyLengthSeconds = 60;
				}
			}
		}
	}
}

void ALobbyGamestate::SetIsReady(int _player, bool _isReady)
{
	if (Server_Players.Num() >= _player)
	{
		if (auto playerState = Server_Players[_player])
		{
			playerState->SetIsReady(_isReady);
		}
	}

	bool isEveryoneReady{true};
	for(auto player : Server_Players)
	{
		if (!player->IsReady)
			isEveryoneReady = false;
	}
	
	if (isEveryoneReady && Server_Players.Num() >= 1)
	{
		ShouldServerTravel = true;
		LobbyLengthSeconds = 2.0f;
	}
	else
	{
		ShouldServerTravel = false;
		IsCountingDown = false;
		PreviousServerTravel = false;
		LobbyLengthSeconds = 2.0f;
	}
}

void ALobbyGamestate::VoteMap(int _player, EFarm _level)
{
	if (_level == EFarm::FARM)
	{
		Farm = Farm + 1;
	}
	else if (_level == EFarm::WINTERFARM)
	{
		WinterFarm = WinterFarm + 1;
	}
}

void ALobbyGamestate::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALobbyGamestate, LobbyLengthMinutes);
	DOREPLIFETIME(ALobbyGamestate, LobbyLengthSeconds);
	DOREPLIFETIME(ALobbyGamestate, IsCountingDown);
	DOREPLIFETIME(ALobbyGamestate, PreviousServerTravel);
	DOREPLIFETIME(ALobbyGamestate, Server_Players);
	DOREPLIFETIME(ALobbyGamestate, bShowMapChoice);

	DOREPLIFETIME(ALobbyGamestate, Farm);
	DOREPLIFETIME(ALobbyGamestate, WinterFarm);
}

