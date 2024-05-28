#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H

#include "Contact.h"
#include <string>

class Acquaintance : public Contact {
private:
    std::string phone;
public:
    Acquaintance(const std::string& name, const std::string& phone);
    std::string getPhone() const;
    ContactType getType() const override;
};

#endif // ACQUAINTANCE_H
