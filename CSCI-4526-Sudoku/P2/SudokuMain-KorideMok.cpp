// Written by James Mok and Niel Koride

#include "UnitTests-KorideMok.hpp"
#include "tools.hpp"

int main(){
    banner();
    cout <<"Begin State Test\n---------------------------------------------------" <<endl;
    testStateFunctions();
    cout <<"\nState Test Completed Successfully\n-----------------------------------------"
           "----------" <<endl;
    cout <<"Begin Square Test\n---------------------------------------------------" <<endl;
    testSquareFunctions();
    cout <<"\nSquare Test Completed Successfully\n-----------------------------------------"
           "----------" <<endl;
    bye();
}