//
// Created by tamir on 3/27/18.
//

#include "FileValue.h"

FileValue::FileValue(const char* initValue):refCount(1) {
    data = new fstream(initValue,ios::out|ios::in);
}

FileValue::~FileValue() {
    delete data;
}