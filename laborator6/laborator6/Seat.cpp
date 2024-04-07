#include "Seat.h"

double Seat::calculateTime(double length, Weather weather) const {
    // Implement calculation based on Seat's characteristics
    // This is a placeholder implementation, actual calculation logic needs to be filled
    double baseTime = length / 90; // Assuming a base time of 1 unit per 90 km
    switch (weather) {
    case Weather::Rain:
        return baseTime * 1.3; // 30% increase in time in rainy weather
    case Weather::Sunny:
        return baseTime; // No change in time in sunny weather
    case Weather::Snow:
        return baseTime * 1.6; // 60% increase in time in snowy weather
    }
}

bool Seat::hasEnoughFuel(double length) const {
    // Implement fuel check for Seat
    // This is a placeholder implementation, actual fuel check logic needs to be filled
    double fuelCapacity = 50; // Assume fuel capacity in liters
    double fuelConsumptionPerKm = 0.08; // Assume fuel consumption per km in liters
    return fuelCapacity >= fuelConsumptionPerKm * length;
}
