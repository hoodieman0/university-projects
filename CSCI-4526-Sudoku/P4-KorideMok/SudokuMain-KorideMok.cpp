#include "UnitTests-KorideMok.hpp"
#include "tools.hpp"

#define FILE "P4output.txt"
#define STREAM cout
// if file output is wanted, use 'unit_test' variable

// argv[1] is the file name used in Board class
int main(int argc, char * const argv[]){
    banner();

    if(argc != 2){ cout<< argc; fatal("!Incorrect Amount Of Arguments!"); }
    ofstream unit_test(FILE);

//    STREAM <<"~Begin Square Test~\n---------------------------------------------------" <<endl;
//    testSquareFunctions(STREAM);
//    STREAM <<"\n~Square Test Completed Successfully~\n-----------------------------------------"
//           "----------" <<endl;

    STREAM <<"~Begin Board Test~\n---------------------------------------------------" <<endl;
    testBoardFunctions(STREAM, argv[1]);
    STREAM <<"\n~Board Test Completed Successfully~\n-----------------------------------------"
           "----------" <<endl;

    unit_test.close();

    bye();
}