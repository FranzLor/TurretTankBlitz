// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime) {
    Super::Tick(DeltaTime);

    // make sure tank is not null
    if (Tank) {
        float Distance = FVector::Dist(GetActorLocation(), Tank->GetActorLocation());

        if (Distance <= FireRange) {
            RotateTurret(Tank->GetActorLocation());
        }
    }
}


// Called when the game starts or when spawned
void ATower::BeginPlay()
{
	Super::BeginPlay(); 

    // cast parent ptr to child ptr
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0)); 

}