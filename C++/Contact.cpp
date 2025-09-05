#include "Contact.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


// This constructor intializes a contact object with a name and phone number
// The member intializer list (:name(n), phone(p)) directly sets the member variables
Contact::Contact(string n, string p) : name(n), phone(p) {}

// Sets the contact's name to the provided value
void Contact::setName(string n)
{
    name = n;
}

// Sets the contact's phone number
void Contact::setPhone(string p)
{
    phone = p;
}

// Gets the name of the contact
string Contact::getName() const
{
    return name;
}

// Gets the phone number of the contact
string Contact::getPhone() const
{
    return phone;
}

//displays name and phone number of the contact
void Contact::display() const
{
    cout << "name: " << name << ", Phone: " << phone << endl;
}


