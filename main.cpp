
#include "File.h"
int main() {
    touch("tamir.txt");
    File f("tamir.txt" , "ragag");

    f.getfile() << "Sa";
    touch("tamir.txt");
    cout << f[1];
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