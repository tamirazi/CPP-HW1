//
// Created by tamir on 3/27/18.
//

#include "File.h"


File::File(const char* fileName ,const char* path):name(fileName),path(path) {
    file = new FileValue(fileName);
}

File::File(const File& elm):file(elm.file) {
    ++file->refCount;
}
File::~File() {
    if(--file->refCount == 0){
        delete file;
    }
}

char File::operator[](fstream::pos_type i) const {
    int length = file->data->tellg();
    file->data->seekg (0, file->data->end);
    file->data->seekg (0, file->data->beg);
    if(i >= length)
        throw std::range_error(("can't read on location"));
    file->data->seekg(i);
    return char(file->data->peek());

}

CharProxy File::operator[](fstream::pos_type i) {
    int length = file->data->tellg();
    file->data->seekg (0, file->data->end);
    file->data->seekg (0, file->data->beg);
    if(i >= length)
        throw std::range_error(("can't write on location"));
    return CharProxy(*file->data , i);
}
File& File::operator=(const File& elm) {
    if(file == elm.file)
        return *this;

    if(--file->refCount == 0)
        delete file;

    file = elm.file;
    ++file->refCount;
    return *this;

}
void File::cat() const {
    char c;
    file->data->seekg(file->data->beg);
  if(file->data->is_open()){
      cout << file->data->rdbuf();
  } else
      throw "the file is not open";
    cout << endl;
    file->data->clear();
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
    file->data->seekg(file->data->beg);

    if (file->data->is_open()) {
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
    }
    else
        throw "wc function , the fle is not open";

    cout << "Lines: " << lines << " Words: " << words << " Characters: " << chars << endl;
    file->data->clear();
}

void copy(const char* source, const char* destination){

    ifstream src(source , ios::in);
    ofstream des(destination , ios::out);
    char c;
    while(!src.eof() && !src.fail()){
        src.get(c);
        des << c;
    }

};

void move(const char* source, const char* destination){
    copy(source,destination);
    if( remove( source ) != 0 )
        cerr <<  "Error deleting file: " << source << endl;
    else
        cout <<  "File successfully deleted"  << endl;
};

