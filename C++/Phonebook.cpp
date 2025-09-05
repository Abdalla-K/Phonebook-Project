#include "Phonebook.h"
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::ofstream;
using std::ifstream;

void Phonebook::addContact(const Contact &c)
{
    contacts.push_back(c); // adds the contact to the end of the vector
}

void Phonebook::displayAll() const
{
    for(size_t i = 0; i < contacts.size(); ++i) {
        contacts[i].display();
    }
}

void Phonebook::searchByname(string name) const
{
    bool found = false;

    for (size_t i = 0; i < contacts.size(); ++i) {
        const Contact &c = contacts[i];
        if(c.getName() == name) {  // compare contact name
            c.display();   // display the matching contact
            found = true;  // change to true
        }
    }

    if(!found) {
        cout << "No contact found with the name: " << name << endl;
    }
}

void Phonebook::searchByphone(string phone) const
{
    bool found = false;

    for (size_t i = 0; i < contacts.size(); ++i) {
        const Contact &c = contacts[i];
        if(c.getPhone() == phone) {  // compare contact name
            c.display();   // display the matching contact
            found = true;  // change to true
        }
    }

    if(!found) {
        cout << "No contact found with the phone number: " << phone << endl;
    }

} 

void Phonebook::deleteContact(string name)
{
    for(size_t i = 0; i < contacts.size(); ++i) {
        const Contact &c = contacts[i];
        if(c.getName() == name) {
           contacts.erase(contacts.begin() + i);
           cout << "contact deleted successfully." << endl;
           return; 
        }
    }
    cout << "No contact found with the name: " << name << endl;
}

void Phonebook::saveTofile(string filename) 
{
    ofstream file(filename);
    if(!file) {
        cout << "Error opening file, please make sure file exists." << endl;
        return;
    }
    for(size_t i = 0; i < contacts.size(); ++i) {
        const Contact &c = contacts[i];
        file << c.getName() << "," << c.getPhone() << endl; // save name and phone number into file
    }
    file.close(); // close the file
    cout << "Contacts saved to " << filename << endl;
}

void Phonebook::loadFromfile(string filename)
{
    ifstream file(filename);

    if(!file) {
        cout << "Error opening file for reading, please make sure file exists." << endl;
        return;
    }

    bool loaded = false;
    string line;
    while(getline(file,line)) {
        size_t comma = line.find(','); // finds the comma
        if (comma != string::npos) {
            string name = line.substr(0, comma);
            string phone = line.substr(comma+1);
            contacts.push_back(Contact(name,phone));
            loaded = true;
        }
    }
    file.close();

    if(loaded) {
        cout << "Contacts from " << filename << " have been loaded" << endl;
    }
    else {
        cout << "No valid contacts found in " << filename << endl;
    }
}