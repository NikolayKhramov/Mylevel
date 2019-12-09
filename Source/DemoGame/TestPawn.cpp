// Fill out your copyright notice in the Description page of Project Settings.

#include "TestPawn.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Camera/CameraComponent.h"

// Sets default values
ATestPawn::ATestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CreateDefaultSubobject<UFloatingPawnMovement>("PawnMovement");
	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>("CubeMesh");
	CameraMesh = CreateDefaultSubobject<UCameraComponent>("CameraMesh");

}

// Called when the game starts or when spawned
void ATestPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATestPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATestPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ATestPawn::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATestPawn::moveRight);

}

void ATestPawn::moveForward(float value)
{
	AddMovementInput(GetActorForwardVector(), value);
}

void ATestPawn::moveRight(float value)
{
	AddMovementInput(GetActorRightVector(), value);

}