//
// Created by tamir on 4/14/18.
//

#ifndef HW1_FOLDER_H
#define HW1_FOLDER_H
#include <cstring>
class Folder{
public:
    string name;
    string path;
    Folder(const char* n , const char* p):name(n) , path(p){};
    const char* getName(){return name.data();}
    const char* getPath(){ return path.data();}
    bool operator==(const char* name)const{
        return ((this->name.compare(name)) == 0) ? true : false;
    }

};

#endif //HW1_FOLDER_H
