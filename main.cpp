
#include "File.h"
#include "Folders.h"
int main() {

    touch("tamir.txt");
    Folders f;
    f.mkdir("V/tmp/");
    f.chdir("V/tmp/");
    f.addFile("tamir.txt");

    f.lproot();

    return 0;
}