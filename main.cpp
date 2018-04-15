
#include "File.h"
#include "Folders.h"
using  namespace std;

int main() {

    Folders terminal;
    terminal.ttouch("V/test.txt");
    terminal.writeToFile("V/test.txt" , 0 , 'd');
    terminal.writeToFile("V/test.txt" , 1 , 'J');
    terminal.writeToFile("V/test.txt" , 2 , 'o');
    terminal.writeToFile("V/test.txt" , 3 , 'n');
    terminal.writeToFile("V/test.txt" , 4 , 'g');

    File *file = &terminal.getFile("V/test.txt");
    file->cat();
    terminal.mkdir("V/tmp/");
    terminal.chdir("V/tmp/");
    cout << terminal.pwd();

    copy("V/test.txt" , "V/tmp/t.dat");
    copy("cpy.txt" , "V/tmp/f.cc");

    terminal.ln("V/tmp/f.cc"  , "V/tmp/cpy.txt");

    terminal.lproot();



    return 0;
}