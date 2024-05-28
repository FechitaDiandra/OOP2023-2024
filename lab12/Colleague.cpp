#include "Colleague.h"

Colleague::Colleague(const std::string& name, const std::string& phone, const std::string& company, const std::string& address)
    : Contact(name), phone(phone), company(company), address(address) {}

std::string Colleague::getPhone() const {
    return phone;
}

std::string Colleague::getCompany() const {
    return company;
}

std::string Colleague::getAddress() const {
    return address;
}

ContactType Colleague::getType() const {
    return ContactType::Colleague;
}
