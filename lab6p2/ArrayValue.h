#pragma once
#include <vector>
#include <memory> // Include <memory> for std::unique_ptr
#include "JsonValue.h"

class ArrayValue : public JsonValue {
    std::vector<std::unique_ptr<JsonValue>> values;
public:
    void add(std::unique_ptr<JsonValue> value) { // Modify the add function to accept unique_ptr
        values.push_back(std::move(value));
    }

    void print(std::ostream& out, int indentation = 0) const override {
        out << "[";
        if (!values.empty()) {
            out << std::endl;
            for (size_t i = 0; i < values.size(); ++i) {
                out << std::string(indentation + 4, ' ');
                values[i]->print(out, indentation + 4);
                if (i != values.size() - 1)
                    out << ",";
                out << std::endl;
            }
            out << std::string(indentation, ' ');
        }
        out << "]";
    }
};
