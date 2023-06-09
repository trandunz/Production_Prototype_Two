#include "LobbyGamemode.h"

#include "Kismet/GameplayStatics.h"
#include "Prototype2/LobbyCharacter.h"
#include "Prototype2/LobbyPlayerState.h"
#include "Prototype2/Prototype2Character.h"
#include "Prototype2/PrototypeGameInstance.h"
#include "Prototype2/Gamestates/LobbyGamestate.h"


ALobbyGamemode::ALobbyGamemode()
{
	PrimaryActorTick.bCanEverTick = true;

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/Characters/BP_Player"));
	
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

void ALobbyGamemode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (HasAuthority())
	{
		if (auto* playerState = NewPlayer->GetPlayerState<ALobbyPlayerState>())
		{
			if (auto* gamestate = GetGameState<ALobbyGamestate>())
			{
				UE_LOG(LogTemp, Warning, TEXT("Player ID Assigned"));
				playerState->Player_ID = gamestate->Server_Players.Add(playerState);

				if (auto* character = Cast<ALobbyCharacter>(NewPlayer->GetCharacter()))
				{
					//character->PlayerMat = PlayerMaterials[playerState->Player_ID];

										
					switch(playerState->Player_ID)
					{
					case 0:
						{
							character->SetActorLocation({567.373744f,-143.041463f,97.0});
							break;
						}
					case 1:
						{
							character->SetActorLocation({324.557804,-231.419228,97.0});
							break;
						}
					case 2:
						{
							character->SetActorLocation({99.813257,-313.219544,97.0});
							break;
						}
					case 3:
						{
							character->SetActorLocation({-122.669679,-394.196701,97.0});
							break;
						}
					default:
						character->SetActorLocation({567.373744f,-143.041463f,97.0});
						break;
					}
				}
				
				
			}
		}
	}
}

void ALobbyGamemode::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	//if (HasAuthority())
	//{
	//	if (auto gameInstance = Cast<UPrototypeGameInstance>(GetGameInstance()))
	//	{
	//		if (auto gamestate = GetGameState<ALobbyGamestate>())
	//		{
	//			for(auto i = 0; i < gamestate->Server_Players.Num(); i++)
	//			{
	//				auto character = Cast<ALobbyCharacter>(gamestate->Server_Players[i]->GetPlayerController()->GetCharacter());
	//
	//				if (character)
	//				{
	//					switch(gameInstance->CharacterColour)
	//					{
	//					case ECharacterColours::RED:
	//						character->PlayerMat = PlayerMaterials[0];
	//						break;
	//					case ECharacterColours::BLUE:
	//						character->PlayerMat = PlayerMaterials[1];
	//						break;
	//					case ECharacterColours::GREEN:
	//						character->PlayerMat = PlayerMaterials[2];
	//						break;
	//					case ECharacterColours::YELLOW:
	//						character->PlayerMat = PlayerMaterials[3];
	//						break;
	//					default:
	//						character->PlayerMat = PlayerMaterials[0];
	//						break;
	//					}
	//				}
	//			}
	//		}
	//	}
	//}
	//

}


