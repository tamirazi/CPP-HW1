
#include "Folders.h"

#include <sstream>


using namespace std;
int main() {

    Folders terminal;
    File* file;
    string line , function , file1 , file2 , name;
    int pos;
    char c;

    while(true){
        getline(cin , line);
        stringstream ss(line);
        getline(ss , function ,' ');

        try{
            if(function == "touch"){
                getline(ss , file1 ,' ');
                terminal.ttouch(file1.data());
                continue;
            }

            if(function == "write"){
                getline(ss , file1 ,' ');
                ss >> pos;
                ss >> c;
                terminal.writeToFile(file1.data(),pos,c);
                continue;
            }

            if(function == "read"){
                getline(ss , file1 ,' ');
                ss >> pos;
                ss >> c;
                terminal.readFromFile(file1.data(),pos);
                continue;

            }
            if(function == "cat"){
                getline(ss , file1 ,' ');
                if(terminal.hasFile(file1.data())){
                    file = &terminal.getFile(file1.data());
                    file->cat();
                }
                else
                    cerr << "cat : File name not found" << endl;
                continue;

            }
            if(function == "wc"){
                getline(ss , file1 ,' ');

                if(terminal.hasFile(file1.data())){
                    file = &terminal.getFile(file1.data());
                    file->wc();
                }else
                    cerr << "wc : File name not found" << endl;

                continue;

            }
            if(function == "ls"){
                getline(ss , file1 ,' ');
                if(terminal.hasFolder(file1.data())){
                    terminal.ls(file1.data());
                }else
                    cerr << "ls : Foldes name not found" << endl;
                continue;

            }
            if(function == "lproot"){
                terminal.lproot();
                continue;
            }
            if(function == "pwd"){
                cout << terminal.pwd() << endl;
                continue;

            }
            if(function == "mkdir"){
                getline(ss , name ,' ');
                terminal.mkdir(name.data());
                continue;

            }
            if(function == "chdir"){
                getline(ss , name ,' ');
                terminal.chdir(name.data());
                continue;

            }
            if(function == "rmdir"){
                getline(ss , name ,' ');
                terminal.rmdir(name.data());
                continue;

            }
            if(function == "copy"){
                getline(ss , file1 ,' ');
                getline(ss , file2 ,' ');
                terminal.copyFile(file1.data() , file2.data());
                continue;

            }
            if(function == "move"){
                getline(ss , file1 ,' ');
                getline(ss , file2 ,' ');
                terminal.moveFile(file1.data() , file2.data());
                continue;

            }
            if(function == "ln"){
                getline(ss , file1 ,' ');
                getline(ss , file2 ,' ');
                terminal.ln(file1.data() , file2.data());
                continue;

            }
            if(function == "exit"){
                break;
            }

            cerr << "no such input command : '" << function << "' please try again" << endl;



        }catch (char const* error){
            cerr << error << endl;
        }

    }

    return 0;
}