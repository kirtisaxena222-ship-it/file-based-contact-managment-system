#include "Contact.h"
#include <fstream>
#include <algorithm>

Contact::Contact(string n, string p, string e) {
    name = n;
    phone = p;
    email = e;
}

void Contact::input() {
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, name);
    cout << "Enter Phone: ";
    getline(cin, phone);
    cout << "Enter Email: ";
    getline(cin, email);
}

void Contact::display() const {
    cout << "Name: " << name
         << "\nPhone: " << phone
         << "\nEmail: " << email
         << "\n----------------------\n";
}

bool login() {
    string password;
    cout << "Enter system password: ";
    cin >> password;

    if (password == "admin123") return true;
    cout << "Incorrect password!\n";
    return false;
}

void addContact() {
    Contact c;
    ofstream file("contacts.txt", ios::app);
    c.input();
    file << c.name << "|" << c.phone << "|" << c.email << endl;
    file.close();
    cout << "Contact added successfully!\n";
}

vector<Contact> loadContacts() {
    vector<Contact> contacts;
    ifstream file("contacts.txt");
    string line;

    while (getline(file, line)) {
        int p1 = line.find("|");
        int p2 = line.find("|", p1 + 1);

        string name = line.substr(0, p1);
        string phone = line.substr(p1 + 1, p2 - p1 - 1);
        string email = line.substr(p2 + 1);

        contacts.push_back(Contact(name, phone, email));
    }

    file.close();
    return contacts;
}

void saveContacts(vector<Contact>& contacts) {
    ofstream file("contacts.txt");
    for (auto &c : contacts) {
        file << c.name << "|" << c.phone << "|" << c.email << endl;
    }
    file.close();
}

void viewContacts() {
    vector<Contact> contacts = loadContacts();
    for (auto &c : contacts) {
        c.display();
    }
}

void searchContact() {
    vector<Contact> contacts = loadContacts();
    string searchName;
    cin.ignore();
    cout << "Enter name to search: ";
    getline(cin, searchName);

    for (auto &c : contacts) {
        if (c.name.find(searchName) != string::npos) {
            c.display();
            return;
        }
    }
    cout << "Contact not found.\n";
}

void editContact() {
    vector<Contact> contacts = loadContacts();
    string searchName;
    cin.ignore();
    cout << "Enter name to edit: ";
    getline(cin, searchName);

    for (auto &c : contacts) {
        if (c.name == searchName) {
            cout << "Enter new details:\n";
            c.input();
            saveContacts(contacts);
            cout << "Contact updated.\n";
            return;
        }
    }
    cout << "Contact not found.\n";
}

void deleteContact() {
    vector<Contact> contacts = loadContacts();
    string searchName;
    cin.ignore();
    cout << "Enter name to delete: ";
    getline(cin, searchName);

    for (int i = 0; i < contacts.size(); i++) {
        if (contacts[i].name == searchName) {
            contacts.erase(contacts.begin() + i);
            saveContacts(contacts);
            cout << "Contact deleted.\n";
            return;
        }
    }
    cout << "Contact not found.\n";
}

void sortContacts() {
    vector<Contact> contacts = loadContacts();
    sort(contacts.begin(), contacts.end(), [](Contact a, Contact b) {
        return a.name < b.name;
    });
    saveContacts(contacts);
    cout << "Contacts sorted by name.\n";
}
