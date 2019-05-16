// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Riddle.generated.h"

UCLASS( Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WAFFLEWARRIOR_API URiddle : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URiddle();

    /** Generate a new riddle by modifying the text, waffles, and points member variables. */
    UFUNCTION(BlueprintCallable)
    void GenerateNewRiddle();

    /** Text of the riddle. */
    UPROPERTY(BlueprintReadOnly)
    FString Text;

    /** Number of waffles actually requested. */
    UPROPERTY(BlueprintReadOnly)
    int Waffles;

    /** Number of points awarded for completing the current riddle. */
    UPROPERTY(BlueprintReadOnly)
    float PointsForCompletion;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
