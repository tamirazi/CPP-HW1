//
// Created by tamir on 3/27/18.
//

#ifndef HW1_FILE_H
#define HW1_FILE_H

#include "FileValue.h"
#include <cstring>
#include <iostream>


class File {
public:
    File(const char* name,const char* path);
    File(const File&);
    ~File();
    File& operator= (const File&);
    bool operator==(const char*);
    CharProxy operator [] (fstream::pos_type);
    const char operator [](int)const;
    void cat() const ;
    void wc() const ;
    int getref(){return file->refCount;}
    fstream& getfile(){return *file->data;}
    string getPath(){ return path;}
    string getName(){ return  name;}
    string getVecName(){return vecName;}
    void remove();
    void ln(File&);


private:
    FileValue *file;
    string name;
    string path;
    string vecName;

};
void touch(const char*);
void copy(const char*, const char*);
void move(const char* , const char* );


#endif //HW1_FILE_H
