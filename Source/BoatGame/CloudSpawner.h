// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "CloudSpawner.generated.h"

UCLASS()
class BOATGAME_API ACloudSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACloudSpawner();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UPROPERTY()
		TArray <UStaticMesh*> CloudArray;

	UPROPERTY()
		FVector PlayerLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 CloudAmount = 200;

	UFUNCTION()
		void SpawnCloud();

	UFUNCTION()
		void CheckCloudDistance();
};
