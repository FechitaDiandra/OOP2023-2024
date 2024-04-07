#include "JsonValue.h"
#include "ArrayValue.h"
#include "BoolValue.h" 
#include "NumberValue.h"
#include "ObjectValue.h"
#include "StringValue.h"
#include "NullValue.h"
#include <iostream>

int main() {
    auto array_numbers = std::make_unique<ArrayValue>();
    array_numbers->add(std::make_unique<NumberValue>(5));
    array_numbers->add(std::make_unique<NumberValue>(10));
    array_numbers->add(std::make_unique<NumberValue>(15));

    auto array_strings = std::make_unique<ArrayValue>();
    array_strings->add(std::make_unique<StringValue>("abc"));
    array_strings->add(std::make_unique<StringValue>("def"));
    array_strings->add(std::make_unique<StringValue>("ghi"));

    auto subobject = std::make_unique<ObjectValue>();
    subobject->add("email", std::make_unique<StringValue>("t@gmail.com"));
    subobject->add("name", std::make_unique<StringValue>("T"));
    subobject->add("online", std::make_unique<BoolValue>(true)); // Ensure BoolValue is correctly defined

    auto object = std::make_unique<ObjectValue>();
    object->add("n", std::make_unique<NullValue>());
    object->add("array_numbers", std::move(array_numbers));
    object->add("array_strings", std::move(array_strings));
    object->add("info", std::move(subobject));

    std::cout << "Top node has " << static_cast<unsigned>(*object) << " subnodes\n";

    object->print(std::cout);

    return 0;
}
