//
// Created by tamir on 4/8/18.
//

#ifndef HW1_CHARPROXY_H
#define HW1_CHARPROXY_H
#include "FileValue.h"

class CharProxy {
public:
    CharProxy(fstream &file, fstream::pos_type pos):file_(file),pos_(pos){}

    CharProxy& operator= (char c){
        file_.seekp(pos_);
        file_.put(c);
        return *this;
    }
    operator char(){
        file_.seekg(pos_);
        return char(file_.get());
    }


private:
    fstream& file_;
    fstream::pos_type pos_;

};


#endif //HW1_CHARPROXY_H
