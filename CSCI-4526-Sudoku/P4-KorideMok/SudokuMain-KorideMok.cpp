#include "UnitTests-KorideMok.hpp"
#include "tools.hpp"

#define FILE "Output.txt"
#define STREAM cout
// if file output is wanted, use 'unit_test' variable

int main(){
    banner();

    ofstream unit_test(FILE);

    cout <<"~Begin Square Test~\n---------------------------------------------------" <<endl;
    testSquareFunctions(STREAM);
    cout <<"\n~Square Test Completed Successfully~\n-----------------------------------------"
           "----------" <<endl;

    cout <<"~Begin Board Test~\n---------------------------------------------------" <<endl;
    testBoardFunctions(STREAM);
    cout <<"\n~Board Test Completed Successfully~\n-----------------------------------------"
           "----------" <<endl;

    unit_test.close();

    bye();
}