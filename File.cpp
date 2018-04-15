#include <string>//
// Created by tamir on 3/27/18.
//

#include "File.h"



File::File(const char* fileName ,const char* p):name(fileName),path(p) {
    file = new FileValue(fileName);
    name = fileName ;
    path = p;

}

File::File(const File& elm):file(elm.file) , name(elm.name) , path(elm.path) {
    if(elm.file->shareable){
        file = elm.file;
        ++file->refCount;
    }
    else
        file = new FileValue(elm.name.data());

}
File::~File() {
    if(--file->refCount == 0){
        delete file;
    }
    //cout << "File Des" <<endl;
}

const char File::operator[](int i)const  {
    //cout << "operator[r]" << endl;
    if(!file->data->is_open()){
        file->data->open(this->name , ios::out);
        if(file->data->fail())
            throw  std::runtime_error("operator[w] : cannot open file");
    }
    file->data->seekg (0, file->data->end);
    int length = file->data->tellg();
    file->data->seekg (0, file->data->beg);
    if(i > length)
        throw ("can't read on location");
    file->data->seekg(i);
    return char(file->data->peek());

}
CharProxy File::operator[](fstream::pos_type i){
    //cout << "operator[w]" << endl;
    //open file
    if(!file->data->is_open()){
        file->data->open(this->name , ios::out);
        if(file->data->fail())
            throw  std::runtime_error("operator[w] : cannot open file");
    }
    if(file->refCount > 1){
        --file->refCount;
        file = new FileValue(this->name.data());
    }
    file->shareable = false;

    file->data->seekg (0, file->data->end);
    int length = file->data->tellg();
    file->data->seekg (0, file->data->beg);
    if(i > length){
        file->data->close();
        throw std::range_error(("can't write on location"));
    }
    file->data->clear();

    return CharProxy(*file->data , i);
}
File& File::operator=(const File& elm) {
    if(file == elm.file)
        return *this;

    if(--file->refCount == 0)
        delete file;
    if(elm.file->shareable){
        file = elm.file;
        ++file->refCount;
    } else
        file = new FileValue(elm.name.data());

    return *this;

}
void File::cat() const {
    char c;
    string line;
    //open the file to read
    if(!file->data->is_open()){
        file->data->open(this->name , ios::in);
        if(file->data->fail())
            throw "cat error : cannot find file";
    }

    file->data->seekg( 0 ,file->data->beg);
    //print the file;
    cout << file->data->rdbuf();
//    while(getline(*file->data , line))
//        cout << line << endl;
    cout << endl;
    file->data->clear();
    //close file
    file->data->close();
}
void touch(const char *name) {
    ofstream file;
    file.open(name);
    file.flush();
    file.close();
}
void File::wc() const {
    int lines = 0;
    int words = 0;
    int chars = 0;
    char c;
    string word;

    //open the file to read
    if(!file->data->is_open()){
        file->data->open(this->name , ios::in);
        if(file->data->fail())
            throw "cat error : cannot find file";
    }

        file->data->seekg(file->data->beg);
        file->data->clear();
        while(!file->data->eof() && !file->data->fail()){    //count only words in file
            if(*file->data >> word){
                words++;
            }
        }
        file->data->seekg(file->data->beg);
        if(words > 0)
            lines++;                        //count only the first line
        while(!file->data->eof() && !file->data->fail()){          //count chars and lines in file
            if(file->data->get(c)){
                if(c != '\n')
                    chars++;
                else{
                    lines++;
                    chars++;
                }
            }
        }


    cout << "Lines: " << lines << " Words: " << words << " Characters: " << chars << endl;
    file->data->clear();
}
void File::remove() {
    if(--file->refCount == 0){
        delete file;
    }
}
bool File::operator==(const char* name) {
    return (!(path.compare(name) == 0)) ? true : false;
}
void copy(const char* source, const char* destination){
    ifstream src(source ,ios::in);
    //open destination file and put the out sequence at the end od the file
    ofstream des(destination , ios::out );
    char c;
    //copy
    while(!src.eof() && src.get(c)){
        des << c;
    }
    //close all files
    src.clear();
    src.close();
    des.clear();
    des.close();

};
void move(const char* source, const char* destination){
    copy(source,destination);
    //remove the file out side the function
};
void File::ln(File& target) {
    if(--target.file->refCount == 0)
        delete target.file;
    target.file = file;
    ++file->refCount;
}


