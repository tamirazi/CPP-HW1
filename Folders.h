//
// Created by tamir on 3/27/18.
//

#ifndef HW1_FOLDERS_H
#define HW1_FOLDERS_H

#include <vector>
#include "File.h"

class Folders {
public:

    Folders();
    void mkdir(const char*);
    void chdir(const char*);
    void rmdir(const char*);
    void ls(const char*);

    void lproot();
    void pwd();

private:
    string name;
    string path;
};


#endif //HW1_FOLDERS_H
