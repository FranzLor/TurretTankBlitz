// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TURRETTANKBLITZ_API ATank : public ABasePawn
{
	GENERATED_BODY()

public:
	ATank();

private:
	UPROPERTY(VisibleAnywhere, category = "Components")
	class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, category = "Movement")
	float Speed = 100.0f;

	UPROPERTY(EditAnywhere, category = "Movement")
	float TurnRate = 45.0f;

	void Move(float Value);
	void Turn(float Value);


public:
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
};
