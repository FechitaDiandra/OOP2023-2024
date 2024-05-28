#ifndef CONTACT_H
#define CONTACT_H

#include <string>

enum class ContactType {
    Friend,
    Acquaintance,
    Colleague
};

class Contact {
protected:
    std::string name;
public:
    Contact(const std::string& name);
    virtual ~Contact() = default;
    std::string getName() const;
    virtual ContactType getType() const = 0;
};

#endif // CONTACT_H
