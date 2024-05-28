#include <iostream>
#include "AddressBook.h"
#include "Friend.h"
#include "Aquaintance.h"
#include "Colleague.h"

int main() {
    AddressBook addressBook;

    // Adding contacts
    addressBook.addContact(new Friend("Alice", "1990-01-01", "123-456-7890", "123 Wonderland Ave"));
    addressBook.addContact(new Acquaintance("Bob", "987-654-3210"));
    addressBook.addContact(new Colleague("Charlie", "555-555-5555", "Tech Inc.", "456 Tech St"));

    // Searching for a contact
    Contact* contact = addressBook.searchContactByName("Alice");
    if (contact) {
        std::cout << "Found contact: " << contact->getName() << std::endl;
    }
    else {
        std::cout << "Contact not found." << std::endl;
    }

    // Listing friends
    std::vector<Friend*> friends = addressBook.getFriends();
    std::cout << "Friends in address book:" << std::endl;
    for (Friend* friendContact : friends) {
        std::cout << "Name: " << friendContact->getName() << ", DOB: " << friendContact->getDob() << std::endl;
    }

    // Deleting a contact
    addressBook.deleteContact("Alice");
    contact = addressBook.searchContactByName("Alice");
    if (!contact) {
        std::cout << "Alice successfully deleted." << std::endl;
    }

    return 0;
}
