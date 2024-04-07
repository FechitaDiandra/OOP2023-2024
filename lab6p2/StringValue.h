
#pragma once
#include <string>
#include "JsonValue.h"

class StringValue : public JsonValue {
    std::string value;
public:
    StringValue(const std::string& val) : value(val) {}

    void print(std::ostream& out, int indentation = 0) const override {
        out << '"' << value << '"';
    }
};
