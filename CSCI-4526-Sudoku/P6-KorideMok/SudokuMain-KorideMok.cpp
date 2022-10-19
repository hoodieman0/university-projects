#include "UnitTests-KorideMok.hpp"
#include "tools.hpp"

#define FILE "P6output.txt"
#define STREAM cout
// if file output is wanted, use 'unit_test' variable

// argv[1] is the file name used in Board class
int main(int argc, char* const argv[]){
    banner();

    if (argc != 2){ fatal("!Incorrect Amount Of Arguments!"); }
    ofstream unit_test(FILE);

    testP6(STREAM, argv[1]);

    unit_test.close();

    Game obj(argv[1]);
    obj.run();

    bye();
}

//TODO make unit tests use assert functions