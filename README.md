# Linux Utility Toolkit

A menu-driven C++ application that provides a simple interface for performing basic Linux operations using commands covered in our coursework.

## About the Project

Linux Utility Toolkit is a mini project developed as part of our coursework. Its purpose is to demonstrate the practical application of basic Linux commands through a simple C++ application.

Instead of manually executing commands in the terminal, users can select operations from a menu and perform them through the application.

## Features

The application is divided into the following modules:

1. **File Management**
   - List files
   - Create files
   - Copy and move files

2. **Directory Management**
   - Create directories
   - Remove empty directories
   - Display the current working directory

3. **Compression and Archiving**
   - Create ZIP archives
   - Extract ZIP archives
   - Create and extract TAR archives

4. **User and Group Information**
   - Display user ID
   - Display group ID
   - Display associated groups
   - Display username

5. **Permission Management**
   - View file permissions
   - Modify file permissions
   - Understand owner, group and other access permissions

6. **Network Diagnostics**
   - Check network connectivity
   - Display hostname
   - Test internet speed (speedtest-cli)

## Technologies Used

- **Programming Language:** C++
- **Operating System:** Linux
- **Compiler:** GCC (g++)
- **Linux Commands:** mkdir, ls, pwd, cp, mv, zip, unzip, tar, id, groups, chmod, ping, hostname, speedtest-cli

## Project Structure

```text
Linux-Utility-Toolkit/
│
├── main.cpp
├── common.hpp
├── common.cpp
│
├── file_manager.hpp
├── file_manager.cpp
├── directory_manager.hpp
├── directory_manager.cpp
├── archive_manager.hpp
├── archive_manager.cpp
├── user_group.hpp
├── user_group.cpp
├── permission_manager.hpp
├── permission_manager.cpp
├── network_tools.hpp
├── network_tools.cpp
│
├── workspace/
└── README.md
```

## Requirements

- A Linux-based operating system
- GCC C++ compiler
- Required Linux utilities (such as zip, unzip, speedtest-cli)

## Compilation and Execution

Compile the project using:

```bash
g++ -std=c++17 main.cpp common.cpp file_manager.cpp directory_manager.cpp archive_manager.cpp user_group.cpp permission_manager.cpp network_tools.cpp -o linux_toolkit
```

Run the application:

```bash
./linux_toolkit
```

## Team Members

| Member | Responsibility |
|---|---|
| Member 1 | Main Application and Integration |
| Member 2 | File Management |
| Member 3 | Directory Management |
| Member 4 | Compression and Archiving |
| Member 5 | User and Group Information |
| Member 6 | Permission Management |
| Member 7 | Network Diagnostics |
| Member 8 | Common Utilities, Testing and Documentation |

## Learning Objectives

- Understand and apply basic Linux commands.
- Learn how C++ interacts with the Linux operating system.
- Understand file and directory management.
- Explore Linux permissions and user groups.
- Understand basic compression, archiving and networking.
- Practice modular programming and teamwork.

## Note

This project is intended for educational purposes and demonstrates basic Linux operations through a C++ interface.
