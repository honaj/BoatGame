// Fill out your copyright notice in the Description page of Project Settings.

#include "BoatGame.h"
#include "CloudSpawner.h"


// Sets default values
ACloudSpawner::ACloudSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACloudSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACloudSpawner::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	PlayerLocation = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetActorLocation();

	if (CloudArray.Num() < CloudAmount)
	{
		SpawnCloud();
	}

	if (CloudArray.Num() > 0)
	{
		CheckCloudDistance();
	}
}

void ACloudSpawner::SpawnCloud()
{
	
}

void ACloudSpawner::CheckCloudDistance()
{

}