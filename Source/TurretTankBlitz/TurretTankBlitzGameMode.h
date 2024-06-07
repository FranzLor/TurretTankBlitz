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

private:
	class ATank* Tank;
	
};



