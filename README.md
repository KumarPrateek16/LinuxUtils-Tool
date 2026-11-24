# Linux Utility Toolkit

A modular, menu-driven C++ application that provides an intuitive command-line interface for performing basic Linux operations using system commands covered in coursework.

---

## About the Project

**Linux Utility Toolkit** is a collaborative mini project developed to demonstrate practical interactions between C++ and the Linux operating system. 

Instead of typing individual shell commands with manual flags, users can execute essential operations through a structured, interactive menu. The project emphasizes modular programming, clean separation of concerns, and team-based software integration.

---

## Features & Modules

The application is organized into 6 core functional modules:

1. **File Management**
   - Create new files (`touch`)
   - Copy files to a target path (`cp`)
   - Move or rename files (`mv`)
   - List files with detailed attributes (`ls -la`)

2. **Directory Management**
   - Display current working directory (`pwd` / `fs::current_path`)
   - List directory contents with entry types (`[DIR]`, `[FILE]`)
   - Create new directories (`mkdir`)
   - Remove empty directories
   - Remove non-empty directories recursively

3. **Compression & Archiving**
   - Create ZIP archives (`zip -r`)
   - Extract ZIP archives (`unzip`)
   - Create TAR and compressed TAR.GZ archives (`tar -cvf` / `tar -czvf`)
   - Extract TAR and TAR.GZ archives (`tar -xvf` / `tar -xzvf`)
   - View archive contents before extraction (`unzip -l` / `tar -tvf`)

4. **User & Group Information**
   - Display User ID (`id -u`)
   - Display Group ID (`id -g`)
   - Display associated groups (`groups`)
   - Display current logged-in username (`whoami`)

5. **Permission Management**
   - View file and folder permissions (`ls -ld`)
   - Modify permissions using Octal notation (e.g., `chmod 755`)
   - Modify permissions using Symbolic notation (e.g., `chmod u+x,go-w`)

6. **Network Diagnostics**
   - Check network connectivity by pinging a host (`ping -c 4`)
   - Ping a custom website or IP address
   - Display system hostname (`hostname`)
   - Test internet download/upload speeds & latency (`speedtest-cli --simple`)

---

## Prerequisites & Installation

Before compiling and running the toolkit, ensure you have the required compiler and command-line utilities installed on your system.

### One-Line Install Command

**On Debian / Ubuntu / Linux Mint / Kali / WSL:**
```bash
sudo apt update && sudo apt install -y build-essential g++ zip unzip tar speedtest-cli
```

**On Fedora / RHEL:**
```bash
sudo dnf install -y gcc-c++ zip unzip tar speedtest-cli
```

**On Arch Linux:**
```bash
sudo pacman -S --noconfirm base-devel zip unzip tar speedtest-cli
```

---

## How to Run

### Method 1: One-Click Launcher (Recommended)

A launcher script (`linux_toolkit`) is provided in the root directory. It automatically checks for `g++`, compiles any updated source files, and opens the main menu.

1. Grant execute permissions to the script:
   ```bash
   chmod +x linux_toolkit
   ```

2. Run the toolkit:
   ```bash
   ./linux_toolkit
   ```

---

### Method 2: Manual Compilation & Execution

If you prefer to compile manually using GCC (`g++`):

1. **Compile all modules:**
   ```bash
   g++ -std=c++17 main.cpp file_manager.cpp directory_manager.cpp archive_manager.cpp user_group.cpp permissions.cpp network_tools.cpp -o linux_toolkit_app
   ```

2. **Ensure execute permission:**
   ```bash
   chmod +x linux_toolkit_app
   ```

3. **Run the application:**
   ```bash
   ./linux_toolkit_app
   ```

---

## Project Structure

```text
LinuxUtils-Tool/
│
├── main.cpp                 # Main application entry point & master menu
│
├── file_manager.hpp         # Module 1: File management headers
├── file_manager.cpp         # Module 1: File management implementation
│
├── directory_manager.hpp    # Module 2: Directory management headers
├── directory_manager.cpp    # Module 2: Directory management implementation
│
├── archive_manager.hpp      # Module 3: Archiving & compression headers
├── archive_manager.cpp      # Module 3: Archiving & compression implementation
│
├── user_group.hpp           # Module 4: User & group information headers
├── user_group.cpp           # Module 4: User & group information implementation
│
├── permissions.hpp          # Module 5: Permission management headers
├── permissions.cpp          # Module 5: Permission management implementation
│
├── network_tools.hpp        # Module 6: Network diagnostics headers
├── network_tools.cpp        # Module 6: Network diagnostics implementation
│
├── linux_toolkit            # Executable bash launcher script
├── .gitignore               # Git ignore configuration
├── LICENSE                  # Project license
└── README.md                # Project documentation
```

---

## Technologies Used

- **Language:** C++ (C++17)
- **Compiler:** GCC (`g++`)
- **Target OS:** Linux (Ubuntu/Debian, Fedora, Arch, WSL)
- **Linux Utilities:** `touch`, `cp`, `mv`, `ls`, `mkdir`, `pwd`, `zip`, `unzip`, `tar`, `id`, `groups`, `whoami`, `chmod`, `ping`, `hostname`, `speedtest-cli`

---

## Team Members & Responsibilities

| Member | Responsibility | Assigned Module |
|---|---|---|
| **Member 1** | Main Application & Integration | `main.cpp` |
| **Member 2** | File Management | `file_manager.hpp`, `file_manager.cpp` |
| **Member 3** | Directory Management | `directory_manager.hpp`, `directory_manager.cpp` |
| **Member 4** | Compression & Archiving | `archive_manager.hpp`, `archive_manager.cpp` |
| **Member 5** | User & Group Information | `user_group.hpp`, `user_group.cpp` |
| **Member 6** | Permission Management | `permissions.hpp`, `permissions.cpp` |
| **Member 7** | Network Diagnostics | `network_tools.hpp`, `network_tools.cpp` |
| **Member 8** | Common Utilities, Testing & Documentation | Input validation, testing, `README.md` |

---

## Learning Objectives

- Bridge theoretical Linux concepts with practical C++ implementations.
- Practice modular application design using separate header and source files.
- Gain hands-on experience with Linux file permissions, archiving, network tools, and system calls.
- Learn collaborative version control workflows using Git and GitHub.

---

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
