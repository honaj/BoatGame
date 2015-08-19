// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "TimeControl.generated.h"

UCLASS()
class BOATGAME_API ATimeControl : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimeControl();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(Exec)
		virtual void SetTime(float Time);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		float NewTime;
};
