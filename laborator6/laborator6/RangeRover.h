#pragma once
#ifndef RANGEROVER_H
#define RANGEROVER_H

#include "Car.h"

class RangeRover : public Car {
public:
    double calculateTime(double length, Weather weather) const override;
    bool hasEnoughFuel(double length) const override;
};

#endif // RANGEROVER_H

