// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Widget_EndgameCheck.generated.h"

/**
 * 
 */
UCLASS()
class PROTOTYPE2_API UWidget_EndgameCheck : public UUserWidget
{
	GENERATED_BODY()

public:
	void EnableDisableMenu();
	
};
