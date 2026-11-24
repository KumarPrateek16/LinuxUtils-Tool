#include "file_manager.hpp"
#include <iostream>
#include <string>
#include <cstdlib>
#include <limits>
static std::string quoteArg(const std::string& s) {
    std::string out = "\"";
    for (char c : s) {
        if (c == '"' || c == '\\' || c == '$' || c == '`') {
            out += '\\';
        }
        out += c;
    }
    out += "\"";
    return out;
}

void createFile() {
    std::string name;
    std::cout << "Enter file name to create: ";
    std::getline(std::cin, name);
    if (name.empty()) {
        std::cout << "File name cannot be empty.\n";
        return;
    }
    std::string cmd = "touch " + quoteArg(name);
    if (std::system(cmd.c_str()) == 0) {
        std::cout << "Created file: " << name << "\n";
    } else {
        std::cout << "Failed to create file.\n";
    }
}

void copyFile() {
    std::string src, dst;
    std::cout << "Enter source file: ";
    std::getline(std::cin, src);
    std::cout << "Enter destination file/path: ";
    std::getline(std::cin, dst);
    if (src.empty() || dst.empty()) {
        std::cout << "Source and destination cannot be empty.\n";
        return;
    }
    std::string cmd = "cp " + quoteArg(src) + " " + quoteArg(dst);
    if (std::system(cmd.c_str()) == 0) {
        std::cout << "Copied " << src << " to " << dst << "\n";
    } else {
        std::cout << "Failed to copy file.\n";
    }
}

void moveFile() {
    std::string src, dst;
    std::cout << "Enter source file: ";
    std::getline(std::cin, src);
    std::cout << "Enter destination file/path: ";
    std::getline(std::cin, dst);
    if (src.empty() || dst.empty()) {
        std::cout << "Source and destination cannot be empty.\n";
        return;
    }
    std::string cmd = "mv " + quoteArg(src) + " " + quoteArg(dst);
    if (std::system(cmd.c_str()) == 0) {
        std::cout << "Moved " << src << " to " << dst << "\n";
    } else {
        std::cout << "Failed to move file.\n";
    }
}

void listFiles() {
    std::string path;
    std::cout << "Enter directory path (blank for current folder): ";
    std::getline(std::cin, path);
    if (path.empty()) {
        path = ".";
    }
    std::string cmd = "ls -la " + quoteArg(path);
    if (std::system(cmd.c_str()) != 0) {
        std::cout << "Failed to list files.\n";
    }
}
void fileManagementMenu() {
    while (true) {
        std::cout << "\n--- File Management Menu ---\n"
                  << "1. Create File\n"
                  << "2. Copy File\n"
                  << "3. Move File\n"
                  << "4. List Files\n"
                  << "0. Back / Exit\n"
                  << "Enter your choice: ";

        int choice = -1;
        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        // Clear the trailing newline so std::getline inside your functions works properly
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                copyFile();
                break;
            case 3:
                moveFile();
                break;
            case 4:
                listFiles();
                break;
            case 0:
                return;
            default:
                std::cout << "Invalid choice. Try again.\n";
                break;
        }
    }
}
