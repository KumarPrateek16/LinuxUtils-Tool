#ifndef PERMISSIONS_HPP
#define PERMISSIONS_HPP

#include <string>

void permissionMenu();
void viewPermissions(const std::string& path);
void changePermissionsOctal(const std::string& path, const std::string& mode);
void changePermissionsSymbolic(const std::string& path, const std::string& expr);

#endif // PERMISSIONS_HPP