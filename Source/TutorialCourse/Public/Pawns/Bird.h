// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/CapsuleComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Bird.generated.h" // This needs to be the FINAL include

UCLASS()
class TUTORIALCOURSE_API ABird : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABird();

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
protected:
	virtual void BeginPlay() override;

private:
	// Capsule Component for the Bird
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule;
};
