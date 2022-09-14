// Written by James Mok and Neelakanta Bharadwaj Koride

#include "UnitTests-KorideMok.hpp"
#include "tools.hpp"


#define FILE "Unit_Test.txt"
#define STREAM cout
// if file output is wanted, use 'unit_test' variable

int main(){
    banner();
    ofstream unit_test(FILE);
    if (!unit_test){
        cerr << "Unable To Create File";
    }
    else {
        //---------------Begin State Test---------------
        cout <<"~Begin State Test~\n---------------------------------------------------" <<endl;
        testStateFunctions(STREAM);
        cout <<"\n~State Test Completed Successfully~\n-----------------------------------------"
               "----------" <<endl;


        //---------------Begin Square Test---------------

        cout <<"~Begin Square Test~\n---------------------------------------------------" <<endl;
        testSquareFunctions(STREAM);
        cout <<"\n~Square Test Completed Successfully~\n-----------------------------------------"
               "----------" <<endl;
        unit_test.close();
    }

    bye();
}