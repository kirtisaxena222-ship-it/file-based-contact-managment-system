#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <vector>
using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;

    Contact() {}
    Contact(string n, string p, string e);

    void input();
    void display() const;
};

void addContact();
void viewContacts();
void searchContact();
void editContact();
void deleteContact();
void sortContacts();

bool login();

#endif
