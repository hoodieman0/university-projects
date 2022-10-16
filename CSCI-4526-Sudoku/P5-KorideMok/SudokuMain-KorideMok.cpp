#include "UnitTests-KorideMok.hpp"
#include "tools.hpp"

#define FILE "P5output.txt"
#define STREAM cout
// if file output is wanted, use 'unit_test' variable

// argv[1] is the file name used in Board class
int main(int argc, char * const argv[]){
    banner();

    //TODO make sure clusters check if mark can happen
    //TODO remove State::turnOff
    //TODO remove board::printClusters
    //TODO derive classes from each other (State from Square)


    if(argc != 2){ fatal("!Incorrect Amount Of Arguments!"); }
    ofstream unit_test(FILE);

    testP5(STREAM, argv[1]);

    unit_test.close();

    bye();
}