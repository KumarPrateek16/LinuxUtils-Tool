#include "permissions.hpp"
#include <iostream>
#include <cstdlib>
#include <limits>
#include <sys/stat.h>

using namespace std;

bool pathExists(const string& path) {
    struct stat buffer;
    return (stat(path.c_str(), &buffer) == 0);
}

bool isValidOctal(const string& mode) {
    if (mode.length() != 3) return false;
    for (char c : mode) {
        if (c < '0' || c > '7') return false;
    }
    return true;
}

void viewPermissions(const string& path) {
    if (!pathExists(path)) {
        cout << "Error: Path does not exist.\n";
        return;
    }
    string cmd = "ls -ld \"" + path + "\"";
    system(cmd.c_str());
}

void changePermissionsOctal(const string& path, const string& mode) {
    if (!pathExists(path)) {
        cout << "Error: Path does not exist.\n";
        return;
    }
    if (!isValidOctal(mode)) {
        cout << "Error: Enter a valid 3-digit octal mode (digits 0-7, e.g., 755).\n";
        return;
    }
    string cmd = "chmod " + mode + " \"" + path + "\"";
    if (system(cmd.c_str()) == 0) {
        cout << "Permissions updated successfully.\n";
        viewPermissions(path);
    }
}

void changePermissionsSymbolic(const string& path, const string& expr) {
    if (!pathExists(path)) {
        cout << "Error: Path does not exist.\n";
        return;
    }
    string cmd = "chmod " + expr + " \"" + path + "\"";
    if (system(cmd.c_str()) == 0) {
        cout << "Permissions updated successfully.\n";
        viewPermissions(path);
    }
}

void permissionMenu() {
    int choice = 0;
    string path, mode;

    while (true) {
        cout << "\n--- Permission Management ---\n";
        cout << "1. View File/Directory Permissions\n";
        cout << "2. Change Permissions (Numeric / Octal, e.g., 755)\n";
        cout << "3. Change Permissions (Symbolic, e.g., u+x)\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter a number.\n";
            continue;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 4) break;

        if (choice >= 1 && choice <= 3) {
            cout << "Enter file or directory path: ";
            getline(cin, path);
        }

        switch (choice) {
            case 1:
                viewPermissions(path);
                break;
            case 2:
                cout << "Enter octal mode (e.g., 644, 755): ";
                getline(cin, mode);
                changePermissionsOctal(path, mode);
                break;
            case 3:
                cout << "Enter symbolic mode (e.g., u+x, go-w): ";
                getline(cin, mode);
                changePermissionsSymbolic(path, mode);
                break;
            default:
                cout << "Invalid choice.\n";
                break;
        }

        if (choice >= 1 && choice <= 3) {
            cout << "\nPress Enter to continue...";
            cin.get();
        }
    }
}
