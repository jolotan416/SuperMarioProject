// Fill out your copyright notice in the Description page of Project Settings.


#include "Mario.h"

// Sets default values
AMario::AMario()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMario::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMario::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMario::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void AMario::MoveCamera(float XMovement, float YMovement) {
	auto currentYControlRotation = GetControlRotation().GetComponentForAxis(EAxis::Type::Y);
	UE_LOG(LogCore, Warning, TEXT("MovementY: %f, CurrentY: %f"), YMovement, currentYControlRotation);

	AddControllerYawInput(XMovement);
	if ((currentYControlRotation >= 0.0f && currentYControlRotation <= 24.0f) ||
		(currentYControlRotation >= 320.0f && currentYControlRotation <= 360.0f) ||
		(currentYControlRotation > 24.0f && currentYControlRotation < 270.0f && YMovement > 0.0f) ||
		(currentYControlRotation > 90.0f && currentYControlRotation < 320.0f && YMovement < 0.0f)) {
		AddControllerPitchInput(YMovement);
	}
}
