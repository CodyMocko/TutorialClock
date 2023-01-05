// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Item.generated.h"

UCLASS()
class TUTORIALCOURSE_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float Amplitude = 0.25f; // This affects the amplitude of the bobbing motion for the item

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sine Parameters")
	float TimeConstant = 5.f; // This affects how long it takes for one full bobbing motionpublic:	

	UFUNCTION(BlueprintPure)
	float TransformedSine(); 

	UFUNCTION(BlueprintPure)
	float TransformedCosine();

	template<typename T>
	T Avg(T First, T Second);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true")) // This makes the default value viewable, but you can't edit it in the editor
	float RunningTime; // This 

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ItemMesh;

};

template<typename T> // You can decide what T represents when you use this function (doubles, vectors, floats, anything that supports addition)
inline T AItem::Avg(T First, T Second)
{
	return (First + Second) / 2;
}
