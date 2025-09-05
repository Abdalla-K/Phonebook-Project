#include "Phonebook.h"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::getline;



int main()
{
    Phonebook pb;
    string filename = " ";

        cout << "Enter the name of the file you would like to load/save contacts from: ";
        getline(cin, filename);
        pb.loadFromfile(filename);

    int option = 0;
    while (option != 6) {
        cout << "===========================================" << endl;
        cout << "               PHONEBOOK MENU                      " << endl;
        cout << "===========================================" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. View All Contacts" << endl;
        cout << "3. Search by Name" << endl;
        cout << "4. Search by Phone Number" << endl;
        cout << "5. Delete Contact" << endl;
        cout << "6. Save & Exit" << endl;
        cin >> option;

        if (cin.fail()) {
            cerr << "That was not a number, please try again." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            continue;
        }

        string name, phone;
        switch (option) {
            case 1:
                cin.ignore(1000, '\n');
                cout << "Enter name: ";
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phone);
                pb.addContact(Contact(name,phone));
                break;
            case 2:
                pb.displayAll();
                break;
            case 3:
                cin.ignore(1000, '\n');
                cout << "Enter name: ";
                getline(cin, name);
                pb.searchByname(name);
                break;
            case 4:
                cin.ignore(1000, '\n');
                cout << "Enter phone number: ";
                getline(cin, phone);
                pb.searchByphone(phone);
                break;
            case 5:
                cin.ignore(1000, '\n');
                cout << "Enter name: ";
                getline(cin, name);
                pb.deleteContact(name);
                break;
            case 6:
                pb.saveTofile(filename);
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "That was not one of the options (1-6), please try again";
                break;
        }
    }

    return 0;
}