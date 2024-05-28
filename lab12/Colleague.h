#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include "Contact.h"
#include <string>

class Colleague : public Contact {
private:
    std::string phone;
    std::string company;
    std::string address;
public:
    Colleague(const std::string& name, const std::string& phone, const std::string& company, const std::string& address);
    std::string getPhone() const;
    std::string getCompany() const;
    std::string getAddress() const;
    ContactType getType() const override;
};

#endif // COLLEAGUE_H
