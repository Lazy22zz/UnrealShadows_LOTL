// Fill out your copyright notice in the Description page of Project Settings.


#include "UE_Gamemode.h"
#include "UE_GameState.h"
#include "PlayerClass/US_Character.h"
#include "PlayerClass/US_PlayerController.h"
#include "PlayerClass/US_PlayerState.h"
#include "UObject/ConstructorHelpers.h"

AUE_Gamemode::AUE_Gamemode()
{
	GameStateClass = AUE_GameState::StaticClass();
	PlayerStateClass = AUS_PlayerState::StaticClass();
	PlayerControllerClass = AUS_PlayerController::StaticClass();

	static ConstructorHelpers::FClassFinder<APawn>
		PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_Character"));
	{
		if (PlayerPawnBPClass.Class != nullptr)
			DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
