// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TurretTankBlitzPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TURRETTANKBLITZ_API ATurretTankBlitzPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	void SetPlayerEnabledState(bool PlayerEnabled);

};
