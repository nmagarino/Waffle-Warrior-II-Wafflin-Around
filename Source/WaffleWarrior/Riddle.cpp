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
	return RiddleType::ARITHMETIC;
    float randNum = FMath::RandRange(0, 1);
    float cumsum = 0;
    for (int i = 0; i < NumberOfRiddleTypes; ++i) {
        cumsum += RiddleTypeProbabilities[i];
        if (randNum < cumsum) {
            return RiddleType(i);
        }
    }
	return RiddleType(0);
}

}

void URiddle::GenerateNewRiddle() {
    switch (SelectRandomRiddleType()) {
	case RiddleType::ARITHMETIC: {
		// Addition riddle
		int sum = FMath::RandRange(1, 7);
		int first = FMath::RandRange(0, sum);
		int second = sum - first;
		Waffles = sum;
		PointsForCompletion = sum * 10;
		Text = "I want\n";
		Text += FString::FromInt(first) + " + " + FString::FromInt(second);
		Text += " waffles";
		HasStrawberry = FMath::RandRange(0, 10) < 5;
		Text += HasStrawberry ? "\nwith a sliced strawberry on top!" : " ";
		break;
	}
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

