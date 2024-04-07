#pragma once
#ifndef FIAT_H
#define FIAT_H

#include "Car.h"

class Fiat : public Car {
public:
    double calculateTime(double length, Weather weather) const override;
    bool hasEnoughFuel(double length) const override;
};

#endif // FIAT_H
