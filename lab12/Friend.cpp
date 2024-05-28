#include "Friend.h"

Friend::Friend(const std::string& name, const std::string& dob, const std::string& phone, const std::string& address)
    : Contact(name), dob(dob), phone(phone), address(address) {}

std::string Friend::getDob() const {
    return dob;
}

std::string Friend::getPhone() const {
    return phone;
}

std::string Friend::getAddress() const {
    return address;
}

ContactType Friend::getType() const {
    return ContactType::Friend;
}
