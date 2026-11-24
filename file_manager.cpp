#include "file_manager.hpp"
#include <iostream>
#include <string>
#include <cstdlib>

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
