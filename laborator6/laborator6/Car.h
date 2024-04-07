#pragma once
#ifndef CAR_H
#define CAR_H

#include "Weather.h"

class Car {
public:
    virtual double calculateTime(double length, Weather weather) const = 0;
    virtual bool hasEnoughFuel(double length) const = 0;
};

#endif // CAR_H
