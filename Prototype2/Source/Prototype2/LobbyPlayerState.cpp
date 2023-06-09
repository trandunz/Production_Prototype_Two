#include "LobbyPlayerState.h"

#include "Net/UnrealNetwork.h"


void ALobbyPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME(ALobbyPlayerState, IsReady);
	DOREPLIFETIME(ALobbyPlayerState, Player_ID);
	DOREPLIFETIME(ALobbyPlayerState, Character);
	DOREPLIFETIME(ALobbyPlayerState, CharacterColour);
}

void ALobbyPlayerState::SetIsReady(bool _isReady)
{
	IsReady = _isReady;
}