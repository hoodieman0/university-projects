// Written by James Mok and Niel Koride

#include "UnitTests-KorideMok.hpp"
#include "tools.hpp"

#define FILE "Output.txt"
#define STREAM cout

int main() {
    banner();
    ofstream unit_test(FILE);
    if (!unit_test) {
        cerr << "Unable To Create File";
    } else {
        //---------------Begin State Test---------------
        cout << "~Begin State Test~\n---------------------------------------------------" << endl;
        testStateFunctions(STREAM);
        cout << "\n~State Test Completed Successfully~\n-----------------------------------------"
                "----------" << endl;
    }
    bye();
}