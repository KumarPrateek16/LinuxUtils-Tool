#include "network_tools.hpp"
#include <iostream>
#include <cstdlib>
#include <string>
#include <limits>

using namespace std;

// funct to call sys cmds
void getsystem(string cmd) {
    system(cmd.c_str());
}

static void pauseEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// 1. network connectivity check
void checkConnectivity() {
    string host;
    cout << "Enter website or IP to ping (e.g. google.com): ";
    cin >> host;
    string cmd = "ping -c 4 " + host;
    getsystem(cmd);
}

// 2. hostname
void displayHostname() {
    cout << "\nHostname:\n";
    getsystem("hostname");
}

// 3. speedtest-cli
void checkSpeed() {
    cout << "\nRunning Speed Test (this may take a few seconds)...\n";
    getsystem("speedtest-cli --simple");
}

// menu for network tooool
void networkMenu() {
    int choice = 0;
    while (choice != 4) {
        cout << "\n=====================================\n";
        cout << "       NETWORK DIAGNOSTICS\n";
        cout << "=====================================\n";
        cout << "1. Check Connectivity (ping)\n";
        cout << "2. Display Hostname\n";
        cout << "3. Internet Speed Test (speedtest-cli)\n";
        cout << "4. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                checkConnectivity();
                pauseEnter();
                break;
            case 2:
                displayHostname();
                pauseEnter();
                break;
            case 3:
                checkSpeed();
                pauseEnter();
                break;
            case 4:
                cout << "Returning to Main Menu...\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}
