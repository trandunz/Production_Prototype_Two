// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget_PlayerHUD.h"

#include "Widget_IngameMenu.h"

void UWidget_PlayerHUD::EnableDisableMenu()
{
	if (IngameMenu->GetVisibility() == ESlateVisibility::Hidden)
	{
		IngameMenu->SetVisibility(ESlateVisibility::Visible);
	}
	else
	{
		IngameMenu->SetVisibility(ESlateVisibility::Hidden);
	}
}
