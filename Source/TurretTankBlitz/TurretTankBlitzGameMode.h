// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "TurretTankBlitzGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TURRETTANKBLITZ_API ATurretTankBlitzGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void ActorDied(AActor* DeadActor);

protected:
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool PlayerWon);

private:
	class ATank* Tank;

	class ATurretTankBlitzPlayerController* TurretTankBlitzPlayerController;

	float StartDelay = 3.f;
	
	void HandleGameStart();

	int32 TargetTowers = 0;
	int32 GetTargetTowersCount();
};
