#include "archive_manager.hpp"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

// Function to call system commands
static void getsystem(const string& cmd) {
    system(cmd.c_str());
}

// 1. Create a ZIP archive
void createZip() {
    string archiveName, source;
    cout << "Enter output zip file name (e.g., backup.zip): ";
    cin >> archiveName;
    cout << "Enter file or folder name to compress: ";
    cin >> source;

    string cmd = "zip -r " + archiveName + " " + source;
    getsystem(cmd);
}

// 2. Extract a ZIP archive
void extractZip() {
    string archiveName;
    cout << "Enter zip file name to extract (e.g., backup.zip): ";
    cin >> archiveName;

    string cmd = "unzip " + archiveName;
    getsystem(cmd);
}

// 3. Create a TAR archive
void createTar() {
    string archiveName, source;
    cout << "Enter output tar file name (e.g., backup.tar or backup.tar.gz): ";
    cin >> archiveName;
    cout << "Enter file or folder name to archive: ";
    cin >> source;

    string cmd;
    if (archiveName.find(".gz") != string::npos || archiveName.find(".tgz") != string::npos) {
        cmd = "tar -czvf " + archiveName + " " + source;
    } else {
        cmd = "tar -cvf " + archiveName + " " + source;
    }
    getsystem(cmd);
}

// 4. Extract a TAR archive
void extractTar() {
    string archiveName;
    cout << "Enter tar file name to extract (e.g., backup.tar or backup.tar.gz): ";
    cin >> archiveName;

    string cmd;
    if (archiveName.find(".gz") != string::npos || archiveName.find(".tgz") != string::npos) {
        cmd = "tar -xzvf " + archiveName;
    } else {
        cmd = "tar -xvf " + archiveName;
    }
    getsystem(cmd);
}

// 5. View contents of an archive
void viewArchive() {
    string archiveName;
    cout << "Enter archive name to view (e.g., backup.zip or backup.tar): ";
    cin >> archiveName;

    string cmd;
    if (archiveName.find(".zip") != string::npos) {
        cmd = "unzip -l " + archiveName;
    } else {
        cmd = "tar -tvf " + archiveName;
    }
    getsystem(cmd);
}

// Menu for Member 4: Compression & Archiving
void archiveMenu() {
    int choice = 0;
    while (true) {
        cout << "\n--- Compression & Archiving ---\n";
        cout << "1. Create ZIP Archive (zip)\n";
        cout << "2. Extract ZIP Archive (unzip)\n";
        cout << "3. Create TAR Archive (tar -cvf / -czvf)\n";
        cout << "4. Extract TAR Archive (tar -xvf / -xzvf)\n";
        cout << "5. View Archive Contents\n";
        cout << "0. Back to Main Menu\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Please enter a valid number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                createZip();
                break;
            case 2:
                extractZip();
                break;
            case 3:
                createTar();
                break;
            case 4:
                extractTar();
                break;
            case 5:
                viewArchive();
                break;
            case 0:
            case 6:
                cout << "Returning to Main Menu...\n";
                return;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}
