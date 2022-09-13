// Written by James Mok and Neelakanta Bharadwaj Koride

#include "UnitTests-KorideMok.hpp"

// ---------------------------------------------------------------------
// Helper function for TestStateFunctions()
// Precondition: State object has been created
// Postcondition: Prints the before a mark and after a mark state of the State
void
statePrintTestCase(ostream& out, State* test){
    out <<"~Before~\n" <<*test;
    out <<"!Mark 1!" <<endl;
    test->mark('1');
    out << "~After~\n" <<*test << endl;
}
// ---------------------------------------------------------------------
// Tests all the functions related to the State Class
// No preconditions
// Prints the state of each test object
void
testStateFunctions(ostream& out){
    out <<"-----------------------------------------------------"
          "-----------------------------------------------------" <<endl;
    out << "Testing the State class from Square-KorideMok.hpp" << endl;
    out << "Expected Output:" << endl;
    out << "1. Null values" << endl;
    out << "2. Empty markable State" << endl;
    out << "3. Numbered unmarkable State" << endl;
    out << "4. Unmarked State with limited poslist\n" << endl;


    out << "1. Null Value Test" << endl;
    State* objOne = new State();
    statePrintTestCase(out, objOne);
    objOne->~State();
    out << endl;

    out << "2. Empty State Test" << endl;
    State* objTwo = new State('-');
    statePrintTestCase(out, objTwo);
    objTwo->~State();
    out << endl;

    out << "3. Fixed State Test" << endl;
    State* objThree = new State('9');
    statePrintTestCase(out, objThree);
    objThree->~State();
    out << endl;

    out << "4. Limited Possibilities Test" << endl;
    State* objFour = new State('~');
    statePrintTestCase(out, objFour);
    objFour->~State();
    out <<"-----------------------------------------------------"
          "-----------------------------------------------------" <<endl;
}

void
squarePrintTestCase(ostream& out, Square* test){
    out << "~Before~\n" <<*test;
    out << "!Mark 1!" << endl;
    test->mark('1');
    out << "~After~\n" <<*test <<endl;
}

void
testSquareFunctions(ostream& out){
    out <<"-----------------------------------------------------"
          "-----------------------------------------------------" <<endl;
    out <<"Testing the Square class from Square-KorideMok.hpp" <<endl;
    out <<"Expected Output:" <<endl;
    out <<"1. Null values" <<endl;
    out <<"2. Square [5,1] is created and marked" <<endl;
    out <<"3. Square [7,3] is created and unmarkable\n" <<endl;

    out <<"1. Null Value Test" <<endl;
    Square* obj1 = new Square();
    squarePrintTestCase(out, obj1);
    obj1->~Square();
    out << endl;

    out <<"2. Markable Square Test" <<endl;
    Square* obj2 = new Square('-', 5, 1);
    squarePrintTestCase(out, obj2);
    obj2->~Square();
    out <<endl;

    out <<"3. Unmarkable Square Test" <<endl;
    Square* obj3 = new Square('5', 7, 3);
    squarePrintTestCase(out, obj3);
    obj3->~Square();
    out <<"-----------------------------------------------------"
          "-----------------------------------------------------" <<endl;
}