#ifndef ARCHIVE_MANAGER_HPP
#define ARCHIVE_MANAGER_HPP

void createZip();
void extractZip();
void createTar();
void extractTar();
void viewArchive();

// Menu for Compression & Archiving
void archiveMenu();
inline void compressionMenu() { archiveMenu(); }
inline void archiveManagerMenu() { archiveMenu(); }

#endif // ARCHIVE_MANAGER_HPP
