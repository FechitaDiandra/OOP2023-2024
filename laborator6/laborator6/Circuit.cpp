#include "Circuit.h"
#include <iostream>
#include <algorithm>

void Circuit::SetLength(double length) {
    this->length = length;
}

void Circuit::SetWeather(Weather weather) {
    this->weather = weather;
}

void Circuit::AddCar(Car* car) {
    cars.push_back(car);
}

void Circuit::Race() {
    raceResults.clear(); // Clear race results before starting a new race
    didNotFinish.clear(); // Clear cars that did not finish before starting a new race

    for (Car* car : cars) {
        if (car->hasEnoughFuel(length)) { // Check if the car has enough fuel to finish the race
            double time = car->calculateTime(length, weather);
            raceResults.push_back(std::make_pair(time, car));
        }
        else {
            didNotFinish.push_back(car);
        }
    }

    // Sort race results based on time (ascending order)
    std::sort(raceResults.begin(), raceResults.end());
}

void Circuit::ShowFinalRanks() const {
    // Display final ranks
    std::cout << "Final Ranks:" << std::endl;
    int rank = 1;
    for (const auto& result : raceResults) {
        std::cout << "Rank " << rank++ << ": Car " << result.second << " - Time: " << result.first << std::endl;
    }
}

void Circuit::ShowWhoDidNotFinish() const {
    // Display cars that did not finish
    std::cout << "Cars that did not finish:" << std::endl;
    for (Car* car : didNotFinish) {
        std::cout << "Car " << car << std::endl;
    }
}
