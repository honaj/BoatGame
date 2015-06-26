// Fill out your copyright notice in the Description page of Project Settings.

#include "BoatGame.h"
#include "MyCharacter.h"


// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Player Camera"));
	PlayerCamera->AttachParent = GetCapsuleComponent();
	PlayerCamera->RelativeLocation = FVector(0, 0, 64.f);
	PlayerCamera->bUsePawnControlRotation = true;

	PhysicsHandle = CreateDefaultSubobject<UPhysicsHandleComponent>(TEXT("Physics Handle"));

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();

	MyController = GetWorld()->GetFirstPlayerController();

	MyCameraManager = MyController->PlayerCameraManager;

	MyCameraManager->ViewPitchMax = 80.f;
	MyCameraManager->ViewPitchMin = -80.f;
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	HitObject = LookForObject(300.f, ECC_WorldDynamic);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

//Line trace
FHitResult AMyCharacter::LookForObject(float TraceRange, ECollisionChannel CollisionType)
{
	FVector Location;
	FRotator Rotation;

	Controller->GetPlayerViewPoint(Location, Rotation);

	const FVector Start = Location;
	const FVector Direction = Rotation.Vector();
	const FVector End = Start + (Direction * TraceRange);

	FCollisionQueryParams Params = FCollisionQueryParams(FName(TEXT("Trace")), true, this);

	FHitResult Hit(ForceInit);

	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, CollisionType, Params);

	return Hit;
}

//Equip something
void AMyCharacter::HoverEquipped(AActor* EquippedItem, FVector Offset, float Speed)
{
	EquippedItem->SetActorRotation(FMath::RInterpTo(EquippedItem->GetActorRotation(), PlayerCamera->GetComponentRotation(), GetWorld()->GetDeltaSeconds(), Speed));
	EquippedItem->SetActorLocation(FMath::VInterpTo(EquippedItem->GetActorLocation(), PlayerCamera->GetComponentLocation() + PlayerCamera->GetComponentRotation().RotateVector(Offset), GetWorld()->GetDeltaSeconds(), Speed));
}

//Pick up physics object
void AMyCharacter::PickUpObject()
{
	if (!PhysicsHandleActive && HitObject.bBlockingHit && HitObject.GetComponent()->IsSimulatingPhysics())
	{
		PhysicsHandleActive = true;
		PhysicsHandle->GrabComponent(HitObject.GetComponent(), HitObject.BoneName, HitObject.Location, true);
	}
}

//Drop physics object
void AMyCharacter::DropObject()
{
	if (PhysicsHandleActive)
	{
		PhysicsHandleActive = false;
		PhysicsHandle->ReleaseComponent();
	}
}

//Set picked up object location
void AMyCharacter::UpdatePickupLocation(float HoldingDistance)
{
	if (PhysicsHandleActive)
	{
		const FVector Location = this->GetActorLocation();
		PhysicsHandle->SetTargetLocationAndRotation(Location + PlayerCamera->GetForwardVector() * HoldingDistance + FVector(0, 0, 50.f), PlayerCamera->GetComponentRotation());
	}
}
