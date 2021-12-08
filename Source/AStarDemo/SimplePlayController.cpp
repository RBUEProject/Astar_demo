// Fill out your copyright notice in the Description page of Project Settings.


#include "SimplePlayController.h"

void ASimplePlayController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASimplePlayController::BeginPlay()
{
	Super::BeginPlay();
}

ATestPawn* ASimplePlayController::GetControlledPawn()const
{
	return Cast<ATestPawn>(GetPawn());
}

void SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	//Super::SetupPlayerInputComponent(InputComponent);
	
}