#include "BMW.h"

double BMW::calculateTime(double length, Weather weather) const {
    // Implement calculation based on BMW's characteristics
    // This is a placeholder implementation, actual calculation logic needs to be filled
    double baseTime = length / 100; // Assuming a base time of 1 unit per 100 km
    switch (weather) {
    case Weather::Rain:
        return baseTime * 1.2; // 20% increase in time in rainy weather
    case Weather::Sunny:
        return baseTime; // No change in time in sunny weather
    case Weather::Snow:
        return baseTime * 1.5; // 50% increase in time in snowy weather
    }
}

bool BMW::hasEnoughFuel(double length) const {
    // Implement fuel check for BMW
    // This is a placeholder implementation, actual fuel check logic needs to be filled
    double fuelCapacity = 60; // Assume fuel capacity in liters
    double fuelConsumptionPerKm = 0.1; // Assume fuel consumption per km in liters
    return fuelCapacity >= fuelConsumptionPerKm * length;
}
