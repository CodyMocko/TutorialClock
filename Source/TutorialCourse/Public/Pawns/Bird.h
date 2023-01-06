// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h" // Typically safe to include include files for constructors
#include "Bird.generated.h" // This needs to be the FINAL include

class UCapsuleComponent;
class USkeletalMeshComponent;
class UInputAction;
class UInputMappingContext;

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
	void MoveForward(float Value);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* BirdMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MoveAction;

	void Move(const FInputActionValue& Value);

private:
	// Capsule Component for the Bird
	UPROPERTY(VisibleAnywhere)
	UCapsuleComponent* Capsule; // Must forward declare this since the header file for it is in the .cpp files

	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* BirdMesh; // This is no longer the reccommended way to declare pointers in the header file
};
