// Written by James Mok and Niel Koride

#include "UnitTests-KorideMok.hpp"

// ---------------------------------------------------------------------
// Helper function for TestStateFunctions()
// Precondition: State object has been created
// Postcondition: Prints the before a mark and after a mark state of the State
void
statePrintTestCase(State* test){
    cout <<"~Before~" << test << endl;
//    test->print();
    cout <<"!Mark!" <<endl;
    test->mark('1');
    cout << "~After~" << test << endl;
//    test->print();
}
// ---------------------------------------------------------------------
// Tests all the functions related to the State Class
// No preconditions
// Prints the state of each test object
void
testStateFunctions(){
    cout << "Testing the State class from Square-KorideMok.hpp" << endl;
    cout << "Expected Output:" << endl;
    cout << "1. Null values" << endl;
    cout << "2. Empty markable State" << endl;
    cout << "3. Numbered unmarkable State" << endl;
    cout << "4. Unmarked State with limited possibilities\n" << endl;


    cout << "1. Null Value Test" << endl;
    State* objOne = new State();
    statePrintTestCase(objOne);
    objOne->~State();
    cout << endl;

    cout << "2. Empty State Test" << endl;
    State* objTwo = new State('-');
    statePrintTestCase(objTwo);
    objTwo->~State();
    cout << endl;

    cout << "3. Fixed State Test" << endl;
    State* objThree = new State('9');
    statePrintTestCase(objThree);
    objThree->~State();
    cout << endl;

    cout << "4. Limited Possibilities Test" << endl;
    State* objFour = new State('~');
    statePrintTestCase(objFour);
    objFour->~State();
    cout << endl;
}

void
squarePrintTestCase(Square* test){
    cout << "~Before~\n" <<*test <<endl;
//    test->print();
    cout << "!Mark!" << endl;
    test->mark('1');
    cout << "~After~\n" << *test <<endl;
//    test->print();
}

void
testSquareFunctions(){
    cout <<"Testing the Square class from Square-KorideMok.hpp" <<endl;
    cout <<"Expected Output:" <<endl;
    cout <<"1. Null values" <<endl;
    cout <<"2. Square [5,1] is created and marked" <<endl;
    cout <<"3. Square [7,3] is created and unmarkable\n" <<endl;

    cout <<"1. Null Value Test" <<endl;
    Square* obj1 = new Square();
    squarePrintTestCase(obj1);
    obj1->~Square();
    cout << endl;

    cout <<"2. Markable Square Test" <<endl;
    Square* obj2 = new Square('-', 5, 1);
    squarePrintTestCase(obj2);
    obj2->~Square();
    cout <<endl;

    cout <<"3. Unmarkable Square Test" <<endl;
    Square* obj3 = new Square('1', 7, 3);
    squarePrintTestCase(obj3);
    obj3->~Square();
    cout <<endl;
}