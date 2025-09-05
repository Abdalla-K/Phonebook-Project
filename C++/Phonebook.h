#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.h"
#include <vector>
using std::string;
using std::vector;

// The Phonebook class manages a collection of Contact objects.
// It provides functions to add, display, search, delete contacts,
// and to save/load contacts from a file
class Phonebook {

    vector<Contact> contacts; // vector to store all contacts dynamically

public:
    // Adds a new Contact to the phonebook
    // Pass by const reference to avoid unnecessary copying
    void addContact(const Contact &c);
    
    // Display all contacts in phonebook
    // marked const so it does not modify the object
    void displayAll() const;

    // searches for contact by name and displays matches
    // marked const so it does not modify the object
    void searchByname(string name) const;

    // searches for contact by phone number
    // marked const so it does not modify object
    void searchByphone(string phone) const;

    // deletes first contact that matches given name
    void deleteContact(string name);

    // saves all contacts to a file
    // marked const so it does not change the object
    void saveTofile(string filename);

    // loads contacts from a file and adds them to the phonebook
    void loadFromfile(string filename);

};


#endif