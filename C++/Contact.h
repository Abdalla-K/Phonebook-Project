#ifndef CONTACT_H
#define CONTACT_H

#include <string>
using std::string;

// The contact class represents a single entry in the phone book.
// Each contact object stores a person's name and phone number
// and provides functions to set, get, and display them.
class Contact {

    string name; // stores contact's name
    string phone; // stores contact's phone number

public:
    // Constructor: allows creating a contact with a name and phone number
    // Default values ("") make both optional when creating an object
    Contact(string n = "", string p = "");
    void setName(string n); // sets contact's name
    void setPhone(string p); // sets contact's phone number
    string getName() const; // returns the contact's name
    string getPhone() const; // returns the contact's phone number
    void display() const; // displays the contact's details name and phone number


};



#endif