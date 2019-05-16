// Fill out your copyright notice in the Description page of Project Settings.

#include "Riddle.h"

// Sets default values for this component's properties
URiddle::URiddle()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URiddle::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

namespace {

enum class RiddleType {
    ARITHMETIC,
    PERCENTAGE,
    PRIME,
    ALGEBRA,
    IMPOSSIBLE
};

float RiddleTypeProbabilities[] = { 0.35, 0.3, 0.25, 0.09, 0.01 };
int NumberOfRiddleTypes = 5;

RiddleType SelectRandomRiddleType() {
    float randNum = FMath::RandRange(0, 1);
    float cumsum = 0;
    for (int i = 0; i < NumberOfRiddleTypes; ++i) {
        cumsum += RiddleTypeProbabilities[i];
        if (randNum < cumsum) {
            return RiddleType(i);
        }
    }
}

}

void URiddle::GenerateNewRiddle() {
    switch (SelectRandomRiddleType()) {
    case RiddleType::ARITHMETIC:
        break;
    case RiddleType::PERCENTAGE:
        break;
    }
}

// Called every frame
void URiddle::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

