#include "UnitTests-KorideMok.hpp"
#include "tools.hpp"
#include "Exceptions.hpp"

#define FILE "P7output.txt"
#define STREAM cout
// if file output is wanted, use 'unit_test' variable

// argv[1] is the file name used in Board class
int main(int argc, char* const argv[]){
    banner();

    try{
        if (argc != 2){ throw StreamException(); }
    }
    catch (Exception e) {
        cerr << e << endl;
        fatal("Incorrect Amount Of Arguments");
    }

    ofstream unit_test(FILE);

    testP6(STREAM, argv[1]);

    unit_test.close();

    Game obj(argv[1]);
    obj.run();

    bye();
}

//TODO make unit tests use assert functions