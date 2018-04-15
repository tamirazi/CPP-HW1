//
// Created by tamir on 3/27/18.
//

#ifndef HW1_FOLDERS_H
#define HW1_FOLDERS_H

#include <vector>
#include <algorithm>
#include "File.h"
#include "Folder.h"
using  namespace std;
class Folders {


public:
    Folders();
    void mkdir(const char* name);
    void chdir(const char*);
    void rmdir(const char*);
    void ls(const char*);
    void lproot();
    const char* pwd();
    void addFile(const char*);
    bool hasFolder(const char*);
    bool hasFile(const char*);


private:
    string current;
    vector<Folder> folders; //folders
    vector<File> files;     //files
};


#endif //HW1_FOLDERS_H
