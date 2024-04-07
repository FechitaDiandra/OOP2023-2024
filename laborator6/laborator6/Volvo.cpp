#include "Volvo.h"

double Volvo::calculateTime(double length, Weather weather) const {
    // Implement calculation based on Volvo's characteristics
    // This is a placeholder implementation, actual calculation logic needs to be filled
    double baseTime = length / 85; // Assuming a base time of 1 unit per 85 km
    switch (weather) {
    case Weather::Rain:
        return baseTime * 1.4; // 40% increase in time in rainy weather
    case Weather::Sunny:
        return baseTime; // No change in time in sunny weather
    case Weather::Snow:
        return baseTime * 1.7; // 70% increase in time in snowy weather
    }
}

bool Volvo::hasEnoughFuel(double length) const {
    // Implement fuel check for Volvo
    // This is a placeholder implementation, actual fuel check logic needs to be filled
    double fuelCapacity = 55; // Assume fuel capacity in liters
    double fuelConsumptionPerKm = 0.07; // Assume fuel consumption per km in liters
    return fuelCapacity >= fuelConsumptionPerKm * length;
}
