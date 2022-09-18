// Written by James Mok and Niel Koride

#include "State-KorideMok.hpp"

// ---------------------------------------------------------------------
// Helper function for TestStateFunctions()
// Precondition: State object has been created
// Postcondition: Prints the before a mark and after a mark state of the State
void
PrintTestCase(ostream& out, State test){
    out << "~Before~\n" <<test <<endl;
    out << "!Mark!" << endl;
    test.mark('1');
    out << "~After~\n" <<test <<endl;
}

// ---------------------------------------------------------------------
// Tests all the functions related to the State Class
// Preconditions: State class is defined
// Postconditions: Prints the given state tests
void
testStateFunctions(ostream& out){
    out << "Testing the State class from State-KorideMok.hpp" << endl;
    out << "Expected Output:" << endl;
    out << "1. Null values" << endl;
    out << "2. Empty markable State" << endl;
    out << "3. Numbered unmarkable State" << endl;
    out << "4. Unmarked State with limited possibilities\n" << endl;


    out << "1. Null Value Test" << endl;
    State objOne;
    PrintTestCase(out, objOne);
    out << endl;

    out << "2. Empty State Test" << endl;
    State objTwo('-');
    PrintTestCase(out, objTwo);
    out << endl;

    out << "3. Fixed State Test" << endl;
    State objThree('9');
    PrintTestCase(out, objThree);
    out << endl;

    out << "4. Limited Possibilities Test" << endl;
    State objFour('~');
    PrintTestCase(out, objFour);
    out << endl;
}