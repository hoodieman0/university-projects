#include "UnitTests-KorideMok.hpp"
#include "tools.hpp"

#define FILE "P4output.txt"
#define STREAM unit_test
// if file output is wanted, use 'unit_test' variable

int main(){
    banner();

    ofstream unit_test(FILE);

    STREAM <<"~Begin Square Test~\n---------------------------------------------------" <<endl;
    testSquareFunctions(STREAM);
    STREAM <<"\n~Square Test Completed Successfully~\n-----------------------------------------"
           "----------" <<endl;

    STREAM <<"~Begin Board Test~\n---------------------------------------------------" <<endl;
    testBoardFunctions(STREAM);
    STREAM <<"\n~Board Test Completed Successfully~\n-----------------------------------------"
           "----------" <<endl;

    unit_test.close();

    bye();
}