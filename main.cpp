
#include "File.h"
int main() {
    touch("tamir.txt");
    File f("tamir.txt" , "ragag");
    File g(f);
    cout << "f ref " << f.getref() <<endl;
    f[fstream::pos_type(0)] = 'f';
    f[fstream::pos_type(1)] = 'i';
    f[fstream::pos_type(2)] = 'l';
    f[fstream::pos_type(3)] = 'e';
    f[fstream::pos_type(4)] = '1';
    f.cat();
    f.wc();
    cout << "f ref " << f.getref() <<endl;

    g[fstream::pos_type(0)] = 't';
    g[fstream::pos_type(1)] = 'a';
    g[fstream::pos_type(2)] = 'm';
    cout << "g ref " << g.getref() <<endl;

//    const char c = f[0];
//    cout << c;

    f.cat();
    f.wc();
//    f[2] = '*';
//
//    f.cat();
    //f.getfile().close();

    //todo : open and close file in evrey function!!

    //todo: f[] call only write operator[]



    return 0;
}