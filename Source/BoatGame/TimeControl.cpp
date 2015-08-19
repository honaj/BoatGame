// Fill out your copyright notice in the Description page of Project Settings.

#include "BoatGame.h"
#include "TimeControl.h"


// Sets default values
ATimeControl::ATimeControl()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATimeControl::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATimeControl::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void ATimeControl::SetTime(float Time)
{
	NewTime = Time;
}