//
// Created by tamir on 3/27/18.
//

#ifndef HW1_FILEVALUE_H
#define HW1_FILEVALUE_H

#include <iostream>
#include <fstream>
using namespace std;

class FileValue {

public:
    int refCount;
    fstream* data;
    FileValue(const char* initValue);
    ~FileValue();

};


#endif //HW1_FILEVALUE_H

