#include "UnitTests-KorideMok.hpp"
#include "tools.hpp"

#define FILE "Output.txt"
#define STREAM cout
// if file output is wanted, use 'unit_test' variable

int main(){
    banner();

    ofstream unit_test(FILE);
    testBoardFunctions(STREAM);
    unit_test.close();

    bye();
}