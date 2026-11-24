#include "directory_manager.hpp"
#include <iostream>
#include <string>

using namespace std;

void directoryManagerMenu() {
    int choice;
    do {
        cout << "\n======= Directory Management =======\n";
        cout << "1. Create directory (mkdir)\n";
        cout << "2. Remove empty directory (rmdir)\n";
        cout << "3. Display current working directory (pwd)\n";
        cout << "0. Back to Main Menu\n";
        choice = getIntInput("Enter your choice: ");

        switch (choice) {
            case 1: {
                string dirName = getStringInput("Enter directory name/path to create: ");
                if (dirName.empty()) {
                    cout << "Error: Directory name cannot be empty.\n";
                } else {
                    runCommand("mkdir -p \"" + dirName + "\"");
                }
                break;
            }
            case 2: {
                string dirName = getStringInput("Enter empty directory name/path to remove: ");
                if (dirName.empty()) {
                    cout << "Error: Directory name cannot be empty.\n";
                } else {
                    runCommand("rmdir \"" + dirName + "\"");
                }
                break;
            }
            case 3: {
                runCommand("pwd");
                break;
            }
            case 0:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 0 and 3.\n";
        }
    } while (choice != 0);
}
