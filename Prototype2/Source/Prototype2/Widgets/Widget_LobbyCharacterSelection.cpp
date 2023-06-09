// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget_LobbyCharacterSelection.h"

#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"
#include "Prototype2/LobbyCharacter.h"
#include "Prototype2/LobbyPlayerState.h"
#include "Prototype2/Prototype2PlayerController.h"
#include "Prototype2/PrototypeGameInstance.h"
#include "Prototype2/Gamestates/Prototype2Gamestate.h"

void UWidget_LobbyCharacterSelection::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	PlayerImage->SetBrushFromTexture(Texture_CowRed);
	PlayerColourImage->SetColorAndOpacity(FLinearColor(0.427083f, 0.100098f, 0.100098f, 1.0f));
}

void UWidget_LobbyCharacterSelection::ChangeCharacterLeft()
{
	
}

void UWidget_LobbyCharacterSelection::ChangeCharacterRight()
{
	
}

void UWidget_LobbyCharacterSelection::ChangeCharacterColourLeft()
{
	//if (auto gameInstance = Cast<UPrototypeGameInstance>(GetGameInstance()))
	//{
	//	switch(gameInstance->CharacterColour)
	//	{
	//	case ECharacterColours::RED:
	//		gameInstance->CharacterColour = ECharacterColours::YELLOW;
	//		break;
	//	case ECharacterColours::BLUE:
	//		gameInstance->CharacterColour = ECharacterColours::RED;
	//		break;
	//	case ECharacterColours::GREEN:
	//		gameInstance->CharacterColour = ECharacterColours::BLUE;
	//		break;
	//	case ECharacterColours::YELLOW:
	//		gameInstance->CharacterColour = ECharacterColours::GREEN;
	//		break;
	//	default:
	//		gameInstance->CharacterColour = ECharacterColours::RED;
	//		break;
	//	}
	//}
//
	//UpdateCharacterImage();
}

void UWidget_LobbyCharacterSelection::ChangeCharacterColourRight()
{
	//if (auto gameInstance = Cast<UPrototypeGameInstance>(GetGameInstance()))
	//{
	//	switch(gameInstance->CharacterColour)
	//	{
	//	case ECharacterColours::RED:
	//		gameInstance->CharacterColour = ECharacterColours::BLUE;
	//		break;
	//	case ECharacterColours::BLUE:
	//		gameInstance->CharacterColour = ECharacterColours::GREEN;
	//		break;
	//	case ECharacterColours::GREEN:
	//		gameInstance->CharacterColour = ECharacterColours::YELLOW;
	//		break;
	//	case ECharacterColours::YELLOW:
	//		gameInstance->CharacterColour = ECharacterColours::RED;
	//		break;
	//	default:
	//		gameInstance->CharacterColour = ECharacterColours::RED;
	//		break;
	//	}
	//}
//
	//UpdateCharacterImage();
}

void UWidget_LobbyCharacterSelection::UpdateCharacterImage()
{
	if (auto playerController = Cast<APrototype2PlayerController>(GetOwningPlayer()))
	{
		if (auto playerState = playerController->GetPlayerState<ALobbyPlayerState>())
		{
			switch(playerState->CharacterColour)
			{
			case ECharacterColours::RED:
				PlayerImage->SetBrushFromTexture(Texture_CowRed);
				PlayerColourImage->SetColorAndOpacity(FLinearColor(0.427083f, 0.100098f, 0.100098f, 1.0f));
				break;
			case ECharacterColours::BLUE:
				PlayerImage->SetBrushFromTexture(Texture_CowBlue);
				PlayerColourImage->SetColorAndOpacity(FLinearColor(0.034125f, 0.118703f, 0.192708f, 1.0f));
				break;
			case ECharacterColours::GREEN:
				PlayerImage->SetBrushFromTexture(Texture_CowGreen);
				PlayerColourImage->SetColorAndOpacity(FLinearColor(0.078957f, 0.192708f, 0.056207f, 1.0f));
				break;
			case ECharacterColours::YELLOW:
				PlayerImage->SetBrushFromTexture(Texture_CowYellow);
				PlayerColourImage->SetColorAndOpacity(FLinearColor(0.317708f, 0.180145, 0.033095, 1.0f));
				break;
			default:
				PlayerImage->SetBrushFromTexture(Texture_CowRed);
				PlayerColourImage->SetColorAndOpacity(FLinearColor(0.427083f, 0.100098f, 0.100098f, 1.0f));
				break;
			}
		}
	}
}

void UWidget_LobbyCharacterSelection::ChangeCharacterColour(bool _right)
{
		UpdateCharacterImage();
		if (auto playerController = Cast<APrototype2PlayerController>(GetOwningPlayer()))
		{
			if (auto playerState = playerController->GetPlayerState<ALobbyPlayerState>())
			{
				int newColour{};

				if (_right)
				{
					newColour = (int)playerState->CharacterColour + 1;
				
				}
				else
				{
					newColour = (int)playerState->CharacterColour - 1;
				}
		
				if (newColour > 3)
				{
					newColour = 0;
				}
				else
				{
					if (newColour < 0)
					{
						newColour = 3;
					}
				}
				
				auto playerID = playerState->Player_ID;
				playerController->UpdateCharacterMaterial(playerID, ECharacters::COW, (ECharacterColours)newColour);
			}
		}
	
}
