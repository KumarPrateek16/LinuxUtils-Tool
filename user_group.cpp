#include "user_group.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

void muhehehehe() {
    int choice;
    while (true) {
        cout << "\n--- User and Group Information ---\n"
             << "1. Display user ID\n"
             << "2. Display group ID\n"
             << "3. Display associated groups\n"
             << "4. Display username\n"
             << "0. Back to main menu\n"
             << "Enter choice: ";
        cin >> choice;
        if (cin.fail()) {
    cin.clear();
    cin.ignore(10000, '\n');
    cout << "Please enter a number.\n";
    continue;
}

        if (choice == 1) system("id -u");
        else if (choice == 2) system("id -g");
        else if (choice == 3) system("groups");
        else if (choice == 4) system("whoami");
        else if (choice == 0) return;
        else cout << "Invalid choice.\n";
    }
}