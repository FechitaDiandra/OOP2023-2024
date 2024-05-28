#include "AddressBook.h"
#include "Friend.h"
#include <algorithm>

AddressBook::~AddressBook() {
    for (Contact* contact : contacts) {
        delete contact;
    }
}

void AddressBook::addContact(Contact* contact) {
    contacts.push_back(contact);
}

void AddressBook::deleteContact(const std::string& name) {
    contacts.erase(std::remove_if(contacts.begin(), contacts.end(),
        [&name](Contact* contact) {
            if (contact->getName() == name) {
                delete contact;
                return true;
            }
            return false;
        }), contacts.end());
}

Contact* AddressBook::searchContactByName(const std::string& name) {
    for (Contact* contact : contacts) {
        if (contact->getName() == name) {
            return contact;
        }
    }
    return nullptr;
}

std::vector<Friend*> AddressBook::getFriends() {
    std::vector<Friend*> friends;
    for (Contact* contact : contacts) {
        if (contact->getType() == ContactType::Friend) {
            friends.push_back(static_cast<Friend*>(contact));
        }
    }
    return friends;
}
