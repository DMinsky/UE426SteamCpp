// Fill out your copyright notice in the Description page of Project Settings.


#include "Online/OnlineGameInstance.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionSettings.h"

UOnlineGameInstance::UOnlineGameInstance()
{
	
}

void UOnlineGameInstance::Init()
{
	if (IOnlineSubsystem* OnlineSubsystem = IOnlineSubsystem::Get())
	{
		SessionInterface = OnlineSubsystem->GetSessionInterface();
		if (SessionInterface.IsValid())
		{
			// Bind delegates here
			SessionInterface->OnCreateSessionCompleteDelegates.AddUObject(
				this, &UOnlineGameInstance::OnCreateSessionComplete);
		}
	}
}

void UOnlineGameInstance::OnCreateSessionComplete(FName ServerName, bool Succeeded)
{
	UE_LOG(LogTemp, Warning, TEXT("OnCreateSessionComplete, Succeeded: %d"), Succeeded);
	if (Succeeded)
	{
		GetWorld()->ServerTravel("/Game/ThirdPersonCPP/Maps/ThirdPersonExampleMap?listen");
	}
}

void UOnlineGameInstance::CreateServer()
{
	UE_LOG(LogTemp, Warning, TEXT("Start Create Server"));
	FOnlineSessionSettings SessionSettings;
	SessionSettings.bAllowJoinInProgress = true;
	SessionSettings.bIsDedicated = false;
	SessionSettings.bIsLANMatch = true;
	SessionSettings.bShouldAdvertise = true;
	SessionSettings.bUsesPresence = true;
	SessionSettings.NumPublicConnections = 8;
	SessionInterface->CreateSession(0, FName("My Session"), SessionSettings);
}

void UOnlineGameInstance::JoinServer()
{
}
