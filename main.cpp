#include "Contact.h"

int main() {

    if (!login()) return 0;

    int choice;

    do {
        cout << "\n==== Advanced Contact Management System ====\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Edit Contact\n";
        cout << "5. Delete Contact\n";
        cout << "6. Sort Contacts\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addContact(); break;
            case 2: viewContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: sortContacts(); break;
            case 7: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 7);

    return 0;
}
