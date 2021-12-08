// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TestPawn.h"
#include "SimplePlayController.generated.h"

/**
 * 
 */
UCLASS()
class ASTARDEMO_API ASimplePlayController : public APlayerController
{
	GENERATED_BODY()
private:
	ATestPawn* GetControlledPawn()const;
	virtual void Tick(float DeltaTime)override;
	virtual void BeginPlay() override;
	void SetupPlayerInputComponent(class UInputComponent* InputComponent);
};
