#include<iostream>
#include<limits>
#include "file_manager.hpp"
#include "network_tools.hpp"
#include "directory_manager.hpp"
#include "permissions.hpp"
#include "user_group.hpp"

using namespace std;
void menu(int &p){
    int x;
    cout<<"Welcome to the Linux Utilities.\nWhich Operation would you like to perform.\n";
    cout<<"1. File Management\n";
    cout<<"2. Directory Management\n";
    cout<<"3. Compression & Archiving\n";
    cout<<"4. User & Group Information\n";
    cout<<"5. Permission Management\n";
    cout<<"6. Network Diagnostics\n";
    cout<<"7. Exit\n";
    cout<<"Enter the number associated with the given operation: ";
    cin>>x;
    switch (x){
    case 1:
        FileManagementMenu();      
        break;
    
    case 2:
        menu2();       
        break;
    
    case 3:
        // Call of the given functions as soon as the members gives them        
        break;
    
    case 4:
        muhehehehe();
        break;
    
    case 5:
        permissionMenu();       
        break;
    
    case 6:
        networkMenu();        
        break;
    
    case 7:
        cout<<"Current Session Over.\n";
        p=0;
        break;
    default:
        cout<<"Enter a valid option";
        break;
    }
}
int main(){
    int p=1;
    while(p){
        menu(p);
    }
}
