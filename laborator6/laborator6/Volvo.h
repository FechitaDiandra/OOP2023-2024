#pragma once
#ifndef VOLVO_H
#define VOLVO_H

#include "Car.h"

class Volvo : public Car {
public:
    double calculateTime(double length, Weather weather) const override;
    bool hasEnoughFuel(double length) const override;
};

#endif // VOLVO_H
