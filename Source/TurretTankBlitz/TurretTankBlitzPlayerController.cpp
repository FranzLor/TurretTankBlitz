// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretTankBlitzPlayerController.h"
#include "GameFramework/Pawn.h"



void ATurretTankBlitzPlayerController::SetPlayerEnabledState(bool PlayerEnabled) {

    if (PlayerEnabled) {
        GetPawn()->EnableInput(this);
    }
    else {
        GetPawn()->DisableInput(this);
    }

    bShowMouseCursor = PlayerEnabled;
}