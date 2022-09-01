// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "OnlineGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UE426STEAMCPP_API UOnlineGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UOnlineGameInstance();

protected:
	virtual void Init() override;
};
