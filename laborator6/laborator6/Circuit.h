#pragma once
#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Car.h"
#include <vector>

class Circuit {
public:
    void SetLength(double length);
    void SetWeather(Weather weather);
    void AddCar(Car* car);
    void Race();
    void ShowFinalRanks() const;
    void ShowWhoDidNotFinish() const;

private:
    double length;
    Weather weather;
    std::vector<Car*> cars;
    std::vector<std::pair<double, Car*>> raceResults; // Store race results (time and car)
    std::vector<Car*> didNotFinish; // Store cars that did not finish the race
};

#endif // CIRCUIT_H
