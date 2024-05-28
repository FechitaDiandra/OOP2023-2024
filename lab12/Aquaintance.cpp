#include "Aquaintance.h"

Acquaintance::Acquaintance(const std::string& name, const std::string& phone)
    : Contact(name), phone(phone) {}

std::string Acquaintance::getPhone() const {
    return phone;
}

ContactType Acquaintance::getType() const {
    return ContactType::Acquaintance;
}
