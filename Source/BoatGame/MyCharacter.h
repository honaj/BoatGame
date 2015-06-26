// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class BOATGAME_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Camera")
	class UCameraComponent* PlayerCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		APlayerCameraManager* MyCameraManager;

	//Controller
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Basics")
		APlayerController* MyController;

	//Interaction
	UFUNCTION(BlueprintPure, Category = "Interaction")
		FHitResult LookForObject(float TraceRange, ECollisionChannel CollisionType);

	UFUNCTION(BlueprintCallable, Category = "Equipment")
		void HoverEquipped(AActor* EquippedItem, FVector Offset, float Speed);

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void PickUpObject();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void DropObject();

	UFUNCTION(BlueprintCallable, Category = "Interaction")
		void UpdatePickupLocation(float HoldingDistance);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
		bool PhysicsHandleActive;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
	class UPrimitiveComponent* PickedUpObject;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Interaction")
	class UPhysicsHandleComponent* PhysicsHandle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Interaction")
		FHitResult HitObject;
	
};
