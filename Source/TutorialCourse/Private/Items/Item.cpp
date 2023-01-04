// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Item.h"
#include "DrawDebugHelpers.h"
#include "TutorialCourse/DebugMacrosCorrect.h"


// Sets default values
AItem::AItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Amplitude = 0.25f; This is technically not initialization, but assignment. Less efficient
	
	int32 AvgInt = Avg<int32>(1, 3);
	UE_LOG(LogTemp, Warning, TEXT("Value is %d"), AvgInt);
}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay(); // Using Super will call the parent version of the function

}

float AItem::TransformedSine()
{
	return Amplitude * FMath::Sin(RunningTime * TimeConstant);
}

float AItem::TransformedCosine()
{
	return Amplitude * FMath::Cos(RunningTime * TimeConstant);
}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;

	// the first float will affect the amplitude, while the second affects frequency
	// float DeltaZ = Amplitude * FMath::Sin(RunningTime * TimeConstant); // period = 2*pi / K where K is how long it takes for a full cycle of sinusoidal movement
	// AddActorWorldOffset(FVector(0.f, 0.f, DeltaZ));

	DRAW_SPHERE_SingleFrame(GetActorLocation());

}

