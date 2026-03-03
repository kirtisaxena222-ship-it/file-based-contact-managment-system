#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;

    void input() {
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Phone: ";
        getline(cin, phone);
        cout << "Enter Email: ";
        getline(cin, email);
    }

    void display() const {
        cout << "Name: " << name
             << ", Phone: " << phone
             << ", Email: " << email << endl;
    }
};

void addContact() {
    Contact c;
    ofstream file("contacts.txt", ios::app);

    c.input();
    file << c.name << "|" << c.phone << "|" << c.email << endl;

    file.close();
    cout << "Contact saved successfully!\n";
}

void viewContacts() {
    ifstream file("contacts.txt");
    string line;

    cout << "\n---- Contact List ----\n";
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void searchContact() {
    ifstream file("contacts.txt");
    string line, searchName;
    bool found = false;

    cin.ignore();
    cout << "Enter name to search: ";
    getline(cin, searchName);

    while (getline(file, line)) {
        if (line.find(searchName) != string::npos) {
            cout << "Found: " << line << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Contact not found.\n";

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n==== Contact Management System ====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
