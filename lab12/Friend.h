#ifndef FRIEND_H
#define FRIEND_H

#include "Contact.h"
#include <string>

class Friend : public Contact {
private:
    std::string dob;
    std::string phone;
    std::string address;
public:
    Friend(const std::string& name, const std::string& dob, const std::string& phone, const std::string& address);
    std::string getDob() const;
    std::string getPhone() const;
    std::string getAddress() const;
    ContactType getType() const override;
};

#endif // FRIEND_H
