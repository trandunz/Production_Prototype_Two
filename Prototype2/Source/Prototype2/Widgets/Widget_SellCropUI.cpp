// Fill out your copyright notice in the Description page of Project Settings.


#include "Widget_SellCropUI.h"

#include "Components/TextBlock.h"

void UWidget_SellCropUI::SetCropValue(int _value)
{
	SellText->SetText(FText::FromString(FString::FromInt(_value)));
}
