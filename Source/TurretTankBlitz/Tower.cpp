// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"

void ATower::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    if (InFireRange()) {
        RotateTurret(Tank->GetActorLocation());
    }
}


// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay(); 

    // cast parent ptr to child ptr
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0)); 

    GetWorldTimerManager().SetTimer(FireRateTimerHandle, this, &ATower::CheckFireCondition, FireRate, true);

}

bool ATower::InFireRange() {
    if (Tank) {
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());
        if (Distance <= FireRange) {
            return true;
        }
    }

    return false;
}



void ATower::CheckFireCondition() {
    if (InFireRange()) {
        Fire();
    }
}
