// Fill out your copyright notice in the Description page of Project Settings.

#include "BoatGame.h"
#include "CloudControl.h"


// Sets default values
ACloudControl::ACloudControl()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACloudControl::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACloudControl::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

