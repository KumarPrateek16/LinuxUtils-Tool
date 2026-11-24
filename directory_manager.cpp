#include<iostream>
#include<filesystem>
#include<limits>
#include "directory_manager.hpp"
using namespace std;
namespace fs = filesystem;

static void pauseEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

//Feature 1 : SHOW CURRENT WORKING DIRECTORY

void showCurrentDirectory(){
    cout<<"Current Working Directory : "<<endl;
    cout<<fs::current_path()<<endl;
}

//FEATURE 2 : LIST DIRECTORY CONTENTS

void listDirectoryContents(){
    try{
        cout<<"Contents of Current Directory : "<<endl;
        for(const auto& entry : fs::directory_iterator(".")){
            if(entry.is_directory()) cout<<"[DIR]";
            else if(entry.is_regular_file()) cout<<"[FILE]";
            else cout<<"[OTHER]";
            cout<<entry.path().filename().string()<<endl;
        }
    }
    catch(const fs::filesystem_error& e){
        cout<<"Error :"<<e.what()<<endl;
    }
}

//FEATURE 3 : CREATE EMPTY DIRECTORY

void createDirectory(){
    string name;
    cout<<"Enter Directory Name : ";
    cin>>name;
    try{
        bool created = fs::create_directory(name);
        if(created) cout<<"Directory Created Successfully!"<<endl;
        else cout<<"Directory Already Exists!"<<endl;
    }
    catch(const fs::filesystem_error& e){
        cout<<"Error : "<<e.what()<<endl;
    }
}

//FEATURE 4 : REMOVE EMPTY DIRECTORY

void removeEmptyDirectory(){
    string name;
    cout<<"Enter Directory Name to remove : ";
    cin>>name;
    try{
        if(!fs::exists(name)){
            cout<<"Directory does not exists!"<<endl;
            return;
        }
        if(!fs::is_directory(name)){
            cout<<"The given path is not a directory!"<<endl;
            return;
        }
        bool removed = fs::remove(name);
        if(removed) cout<<"Empty directory removed successfully!"<<endl;
        else cout<<"Directory could not be removed"<<endl;
    }
    catch(const fs::filesystem_error& e){
        cout<<"Error : "<<e.what()<<endl;
    }
}

//FEATURE 5 : REMOVE NON-EMPTY DIRECTORY

void removeNonEmptyDirectory(){
    string name;
    cout<<"Enter directory name to remove : ";
    cin>>name;
    try{
        if(!fs::exists(name)){
            cout<<"Directory does not exists!"<<endl;
            return;
        }
        if(!fs::is_directory(name)){
            cout<<"The given path is not a directory!"<<endl;
            return;
        }
        
        uintmax_t removed=fs::remove_all(name);
        if(removed>0){
            cout<<"Directory and its contents removed succesfully"<<endl;
            cout<<"Total entries removed : "<<removed<<endl;
        }
        else{
            cout<<"Nothing was removed!"<<endl;
        }
    }
    catch(const fs::filesystem_error& e){
        cout<<"Error : "<<e.what()<<endl;
    }
}

//FEATURE : DROPDOWN MENU TO SELECT

void menu2(){
    int ch;
      do{
        cout<<"\n========== FILE SYSTEM MANAGEMENT ==========\n";
        cout<<"1. Show Current Working Directory"<<endl;
        cout<<"2. List Directory Contents"<<endl;
        cout<<"3. Create Empty Directory"<<endl;
        cout<<"4. Remove Empty Directory"<<endl;
        cout<<"5. Remove Non-Empty Directory"<<endl;
        cout<<"0. Exit"<<endl;

        cout<<"\nEnter your choice : ";
        cin>>ch;

        switch(ch){

            case 1:
                showCurrentDirectory();
                pauseEnter();
                break;

            case 2:
                listDirectoryContents();
                pauseEnter();
                break;

            case 3:
                createDirectory();
                pauseEnter();
                break;

            case 4:
                removeEmptyDirectory();
                pauseEnter();
                break;

            case 5:
                removeNonEmptyDirectory();
                pauseEnter();
                break;

            case 0:
                cout<<"Exiting Program..."<<endl;
                break;

            default:
                cout<<"Invalid Choice! Please try again."<<endl;
        }

    }while(ch != 0);
}
