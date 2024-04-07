#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <memory> // Include <memory> for std::unique_ptr
#include "JsonValue.h"

class ObjectValue : public JsonValue {
    std::vector<std::pair<std::string, std::unique_ptr<JsonValue>>> values;
public:
    void add(const std::string& name, std::unique_ptr<JsonValue> value) { // Modify the add function to accept unique_ptr
        values.emplace_back(name, std::move(value));
    }

    void print(std::ostream& out, int indentation = 0) const override {
        out << "{";
        if (!values.empty()) {
            out << std::endl;
            for (size_t i = 0; i < values.size(); ++i) {
                out << std::string(indentation + 4, ' ');
                out << '"' << values[i].first << "\": ";
                values[i].second->print(out, indentation + 4);
                if (i != values.size() - 1)
                    out << ",";
                out << std::endl;
            }
            out << std::string(indentation, ' ');
        }
        out << "}";
    }

    operator unsigned() const {
        return values.size();
    }
};
