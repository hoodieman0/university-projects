// Written by James Mok and Neelakanta Bharadwaj Koride

#include "UnitTests-KorideMok.hpp"

// ---------------------------------------------------------------------
// Helper function for testStateFunctions()
// Precondition: State object has been created
// Postcondition: Prints the State before and after the mark function is called
void
statePrintTestCase(ostream& out, State test){
    out <<"~Before~\n" <<test;
    out <<"!Mark 1!" <<endl;
    test.mark('1');
    out << "~After~\n" <<test << endl;
}

// ---------------------------------------------------------------------
// Tests all the functions related to the State Class
// Preconditions: State class is defined
// Postconditions: Prints the given state tests
void
testStateFunctions(ostream& out){
    out <<"-----------------------------------------------------"
          "-----------------------------------------------------" <<endl;
    out << "Testing the State class from Square-KorideMok.hpp" << endl;
    out << "Expected Output:" << endl;
    out << "1. Default values" << endl;
    out << "2. Empty markable State" << endl;
    out << "3. Numbered unmarkable State" << endl;
    
    out << "1. Default Value Test" << endl;
    State objOne;
    statePrintTestCase(out, objOne);
    out << endl;

    out << "2. Empty State Test" << endl;
    State objTwo('-');
    statePrintTestCase(out, objTwo);
    out << endl;

    out << "3. Fixed State Test" << endl;
    State objThree('9');
    statePrintTestCase(out, objThree);
    out <<"-----------------------------------------------------"
          "-----------------------------------------------------" <<endl;
}

// ---------------------------------------------------------------------
// Helper function for testSquareFunctions()
// Precondition: Square object has been created
// Postcondition: Prints the Square before and after the mark function is called
void
squarePrintTestCase(ostream& out, Square test){
    out << "~Before~\n" <<test <<endl;
    out << "!Mark 5!" << endl;
    test.mark('5');
    out << "~After~\n" <<test <<endl;
}

// ---------------------------------------------------------------------
// Tests all the functions related to the Square Class
// Preconditions: Square and State class is defined
// Postconditions: Prints the given Square tests
void
testSquareFunctions(ostream& out){
    out <<"-----------------------------------------------------"
          "-----------------------------------------------------" <<endl;
    out <<"Testing the Square class from Square-KorideMok.hpp" <<endl;
    out <<"Expected Output:" <<endl;
    out <<"1. Default values" <<endl;
    out <<"2. Square [5,1] is created and marked" <<endl;
    out <<"3. Square [7,3] is created and unmarkable" <<endl;
    out <<"4. Square[9, 5] is created and validates input\n" <<endl;

    out <<"1. Default Value Test" <<endl;
    Square obj1;
    squarePrintTestCase(out, obj1);
    out << endl;

    out <<"2. Markable Square Test" <<endl;
    Square obj2('-', 5, 1);
    squarePrintTestCase(out, obj2);
    out <<endl;

    out <<"3. Unmarkable Square Test" <<endl;
    Square obj3('5', 7, 3);
    squarePrintTestCase(out, obj3);
    out <<endl;

    out <<"4. Input Validation Test" <<endl;
    Square obj4('-', 9, 5);
    out << "~Before~\n" <<obj4 <<endl;
    out << "!Mark 0!" << endl;
    obj4.mark('0');
    out << "!Mark ~!" << endl;
    obj4.mark('~');
    out << "~After~\n" <<obj4 <<endl;
    out <<"-----------------------------------------------------"
          "-----------------------------------------------------" <<endl;
}

// ---------------------------------------------------------------------
// Tests all the functions related to the Board Class
// Preconditions: Game, Board, Square, and State class are defined,
// Postconditions: Prints the given Board tests
void
testBoardFunctions(ostream& out){
    out <<"-----------------------------------------------------"
          "-----------------------------------------------------" <<endl;
    out <<"Testing the Board class from Board-KorideMok.hpp" <<endl;
    out <<"Expected Output:" <<endl;
    out <<"1. GetPuzzle initializes board" <<endl;
    out <<"2. sub gets Square [1,1]" <<endl;
    out <<"3. sub gets Square [2,4]\n" <<endl;
    /* Unit Test Input File
      t
--3-2-6--
9--3-5--1
--18-64--
--81-29--
7-------8
--67-82--
--26-95--
8--2-3--9
--5-1-3--
      */
    ifstream ifs("P4input.txt");
    ifs.get();

    out <<"1. GetPuzzle and Constructor Test" <<endl;
    Board puzzle(9, ifs);
    out <<puzzle <<endl;
    out <<"~Board Object Created~" <<endl;

    out <<"\n2. sub gets Square [1,1] Test" <<endl;
    out <<puzzle.sub(1, 1) <<endl;

    out <<"\n3. sub gets Square [2,4] Test" <<endl;
    out <<puzzle.sub(2, 4) <<endl;
    out <<"-----------------------------------------------------"
          "-----------------------------------------------------" <<endl;
}