#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "Contact.h"
#include "Friend.h" // Include pentru clasa Friend
#include <vector>

class AddressBook {
private:
    std::vector<Contact*> contacts;
public:
    ~AddressBook();
    void addContact(Contact* contact);
    void deleteContact(const std::string& name);
    Contact* searchContactByName(const std::string& name);
    std::vector<Friend*> getFriends(); // Declara?ia func?iei
};

#endif // ADDRESSBOOK_H
