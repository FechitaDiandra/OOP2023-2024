#ifndef BMW_H
#define BMW_H

#include "Car.h"

class BMW : public Car {
public:
    double calculateTime(double length, Weather weather) const override;
    bool hasEnoughFuel(double length) const override;
};

#endif // BMW_H
