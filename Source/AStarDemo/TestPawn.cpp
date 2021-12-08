// Fill out your copyright notice in the Description page of Project Settings.


#include "TestPawn.h"
#include "Components/InputComponent.h"
// Sets default values
ATestPawn::ATestPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

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
	const float ForwardValue = GetInputAxisValue("MoveForward");
	const float RightValue = GetInputAxisValue("MoveRight");

	const FVector MoveDirection = FVector(ForwardValue,RightValue,0.f).GetClampedToMaxSize(1.0f);
	Movement(MoveDirection,DeltaTime);
}

// Called to bind functionality to input
void ATestPawn::SetupPlayerInputComponent(UInputComponent*PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	check(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward");
	PlayerInputComponent->BindAxis("MoveRight");
}

void ATestPawn::Movement(FVector MoveDirection, float DeltaTime)
{
	const FVector Movement = MoveDirection*MoveSpeed*DeltaTime;
	MoveDirection *= MoveSpeed*DeltaTime;
	if (MoveDirection.Size() > 0)
	{
		SetActorRotation(MoveDirection.Rotation());
		AddActorWorldOffset(MoveDirection,true);
	}
}