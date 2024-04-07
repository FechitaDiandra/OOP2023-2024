#pragma once
#include <iostream>

class JsonValue {
public:
    virtual ~JsonValue() {}

    virtual void print(std::ostream& out, int indentation = 0) const = 0;
};



