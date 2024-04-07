#include "Fiat.h"

double Fiat::calculateTime(double length, Weather weather) const {
    // Implement calculation based on Fiat's characteristics
    // This is a placeholder implementation, actual calculation logic needs to be filled
    double baseTime = length / 80; // Assuming a base time of 1 unit per 80 km
    switch (weather) {
    case Weather::Rain:
        return baseTime * 1.4; // 40% increase in time in rainy weather
    case Weather::Sunny:
        return baseTime; // No change in time in sunny weather
    case Weather::Snow:
        return baseTime * 1.8; // 80% increase in time in snowy weather
    }
}

bool Fiat::hasEnoughFuel(double length) const {
    // Implement fuel check for Fiat
    // This is a placeholder implementation, actual fuel check logic needs to be filled
    double fuelCapacity = 45; // Assume fuel capacity in liters
    double fuelConsumptionPerKm = 0.06; // Assume fuel consumption per km in liters
    return fuelCapacity >= fuelConsumptionPerKm * length;
}
