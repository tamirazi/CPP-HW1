//
// Created by tamir on 3/27/18.
//


#include <cstring>
#include "Folders.h"

Folders::Folders():current("V/") {
    folders.push_back(Folder("V/" ,"V/"));
};


void Folders::mkdir(const char *name) {
    //check if the vector already have folder with that name
    if(find(folders.begin() , folders.end() ,name) != folders.end() ){
        throw logic_error("mkdir error : already have folder with that name");
    } else // if not make new one
        folders.push_back(Folder(name , current.data()));

}
void Folders::chdir(const char* name)  {

    //check if the vector already have folder with that name
    if(hasFolder(name)){
        current = name;
    } else // if not make new one
        throw logic_error("chdir error : no such folder");

}
void Folders::rmdir(const char* name) {
    //remove all folders
    vector<Folder>::iterator it;
    //check if the vector already have folder with that name
    if((it = find(folders.begin() , folders.end() ,name)) != folders.end() ){
        //if pwd is the same as the remove folder name
        if(!(current.compare(name)))
            current = it->path;
        folders.erase(it);

    } else // if not make new one
        throw logic_error("rmdir error : no such folder to delete");


    //remove all files inside that folder
    vector<File>::iterator it2;
    //check if the vector already have file with that path
    remove(files.begin() , files.end() , name);

}
const char* Folders::pwd() {
    return current.data();
}
void Folders::ls(const char* name) {
    //check if the vector already have folder with that name
    if(find(folders.begin() , folders.end() ,name) != folders.end() ){
        //print all folder with that path
        vector<Folder>::iterator first , last;
        first = folders.begin();
        last = folders.end();
        cout << name << ": "<< endl <<"Folders: " << endl;
        for(; first!=last ;first++){
            if(!(first->path.compare(name)) && first->name != name)
                cout << first->name << " ";
        }
        cout << endl;

        vector<File>::iterator f , l;
        f = files.begin();
        l = files.end();
        cout << "Files: " << endl;
        for(; f!=l ;f++){
            if(!(f->getPath().compare(name)))
                cout << f->getName() << " ";
        }

    } else // if not make new one
        throw logic_error("ls error : cannot find folder");


}
void Folders::addFile(const char* fileName) {

    files.push_back(File(fileName , current.data()));
}
bool Folders::hasFile(const char* fileName) {
    //look over the files vector and search file with same name
    vector<File>::iterator f , l;
    f = files.begin();
    l = files.end();

    for(; f!=l ;f++){
        if(!(f->getName().compare(fileName)))   //if found
            return true;
    }
    return false;
}
bool Folders::hasFolder(const char* folderName) {
    vector<Folder>::iterator first , last;
    first = folders.begin();
    last = folders.end();

    for(; first!=last ;first++){
        if(!(first->name.compare(folderName)))
            return true;
    }

    return false;
}
void Folders::lproot() {
    vector<Folder>::iterator first , last;
    first = folders.begin();
    last = folders.end();

    for(; first!=last ;first++){
        ls(first->getName());
    }
}