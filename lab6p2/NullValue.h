#pragma once
#include <iostream>
#include "JsonValue.h"

class NullValue : public JsonValue {
public:
    void print(std::ostream& out, int indentation = 0) const override {
        out << "null";
    }
};
