#include "Contact.h"

Contact::Contact(const std::string& name) : name(name) {}

std::string Contact::getName() const {
    return name;
}
