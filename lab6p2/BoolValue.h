#pragma once

#include "JsonValue.h"

class BoolValue : public JsonValue {
    bool value;
public:
    BoolValue(bool val) : value(val) {}

    void print(std::ostream& out, int indentation = 0) const override {
        out << (value ? "true" : "false");
    }
};
