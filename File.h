//
// Created by tamir on 3/27/18.
//

#ifndef HW1_FILE_H
#define HW1_FILE_H

#include "FileValue.h"
#include "CharProxy.h"

class File {
public:

    File(const char* name,const char* path);
    File(const File&);
    ~File();
    File& operator= (const File&);
    char operator[] (fstream::pos_type i) const ;
    CharProxy operator[] (fstream::pos_type i);
    void cat() const ;
    void wc() const ;
    void remove();
    void ln();
    int getref(){return file->refCount;}
    fstream& getfile(){return *file->data;}

private:
    FileValue *file;
    string name;
    string path;

};
void touch(const char*);
void copy(const char*, const char*);
void move(const char* source, const char* destination);


#endif //HW1_FILE_H
