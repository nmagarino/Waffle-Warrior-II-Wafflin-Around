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
		int type = FMath::RandRange(0, 1);
		int sum = FMath::RandRange(1, 7);
		int first = FMath::RandRange(0, sum);
		int second = sum - first;
		Text = "I want\n";
		if (type == 0) {
			Text += FString::FromInt(first) + " + " + FString::FromInt(second);
			Waffles = sum;
		} else {
			Text += FString::FromInt(sum) + " - " + FString::FromInt(first);
			Waffles = second;
		}
		Text += " waffles";
		HasStrawberry = FMath::RandRange(0, 9) < 3;
		Text += HasStrawberry ? "\nwith a sliced strawberry on top!" : " ";
		PointsForCompletion = Waffles * 10 + (HasStrawberry ? 10 : 0);
		break;
	}
	case RiddleType::PERCENTAGE: {
	
		break;
	}
	case RiddleType::PRIME: {
		int type = FMath::RandRange(0, 1);
		int primes[] = { 2, 3, 5, 7 };
		int val = 0;

		Text = "I want\n";
		if (type == 0) {
			// smallest prime greater than
			val = FMath::RandRange(0, 6);
			for (int i = 0; i < 4; ++i) {
				if (primes[i] > val) {
					Waffles = primes[i];
					break;
				}
			}
			Text += " the smallest prime number greater than " + FString::FromInt(val);
		} else {
			// largest prime less than
			val = FMath::RandRange(3, 10);
			for (int i = 0; i < 4; ++i) {
				if (primes[i] < val) {
					Waffles = primes[i];
					break;
				}
			}
			Text += " the largest prime number less than " + FString::FromInt(val);
		}
		Text += " waffles";
		HasStrawberry = FMath::RandRange(0, 9) < 2;
		Text += HasStrawberry ? "\nwith a sliced strawberry on top!" : " ";
		PointsForCompletion = (Waffles + 3) * 10 + (HasStrawberry ? 20 : 0);
		break;
	}
    }
}

// Called every frame
void URiddle::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

