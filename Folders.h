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
    void addFile(const char* , string path = "");
    void removeFile(const char*);
    bool hasFolder(const char*);
    bool hasFile(const char*);
    File& getFile(const char*);
    int getFileNum(const char*);
    void writeToFile(const char*,const int, const char);
    void readFromFile(const char*,int);
    void moveFile(const char* , const char*);
    void copyFile(const char*,const char*);
    void ln(const char* , const char*);
    void ttouch(const char* );


private:
    string current;
    vector<Folder> folders; //folders
    vector<File> files;     //files
};



#endif //HW1_FOLDERS_H
