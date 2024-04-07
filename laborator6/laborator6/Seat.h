#pragma once
#ifndef SEAT_H
#define SEAT_H

#include "Car.h"

class Seat : public Car {
public:
    double calculateTime(double length, Weather weather) const override;
    bool hasEnoughFuel(double length) const override;
};

#endif // SEAT_H

