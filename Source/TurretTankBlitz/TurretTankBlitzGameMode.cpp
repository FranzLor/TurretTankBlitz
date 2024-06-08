// Fill out your copyright notice in the Description page of Project Settings.


#include "TurretTankBlitzGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "TurretTankBlitzPlayerController.h"

void ATurretTankBlitzGameMode::ActorDied(AActor* DeadActor) {
    if (DeadActor == Tank) {
        Tank->HandleDestruction();

        if (TurretTankBlitzPlayerController) {
            TurretTankBlitzPlayerController->SetPlayerEnabledState(false);
        }
        GameOver(false);
    }
    else if (ATower* DestroyedTower = Cast<ATower>(DeadActor)) {
        DestroyedTower->HandleDestruction();
        --TargetTowers;

        if (TargetTowers == 0) {
            GameOver(true);
        }
    }
}


void ATurretTankBlitzGameMode::BeginPlay() {
    Super::BeginPlay();
    HandleGameStart();

}


void ATurretTankBlitzGameMode::HandleGameStart() {
    TargetTowers = GetTargetTowersCount();

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
    TurretTankBlitzPlayerController = Cast<ATurretTankBlitzPlayerController>(UGameplayStatics::GetPlayerController(this, 0));

    StartGame();

    if (TurretTankBlitzPlayerController) {
        TurretTankBlitzPlayerController->SetPlayerEnabledState(false);

        FTimerHandle PlayerEnableTimerHandle;
        FTimerDelegate PlayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
            TurretTankBlitzPlayerController, 
            &ATurretTankBlitzPlayerController::SetPlayerEnabledState, 
            true
        );

        GetWorldTimerManager().SetTimer(PlayerEnableTimerHandle, PlayerEnableTimerDelegate, StartDelay, false);
    }
}


int32 ATurretTankBlitzGameMode::GetTargetTowersCount() {
    TArray<AActor*> Towers;
    UGameplayStatics::GetAllActorsOfClass(this, ATower::StaticClass(), Towers);
    return Towers.Num();
}