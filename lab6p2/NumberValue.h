#pragma once
#include <iostream>
#include "JsonValue.h"

class NumberValue : public JsonValue {
    int value;
public:
    NumberValue(int val) : value(val) {}

    void print(std::ostream& out, int indentation = 0) const override {
        out << value;
    }
};

