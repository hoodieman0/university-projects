// Written by James Mok and Niel Koride

#include "Square-KorideMok.hpp"
#include <iostream>

// ---------------------------------------------------------------------
// Helper function for TestStateFunctions()
// Precondition: State object has been created
// Postcondition: Prints the before a mark and after a mark state of the State
void
PrintTestCase(State* test){
    std::cout << "~Before~" << std::endl;
    test->Print();
    std::cout << "!Mark!" << std::endl;
    test->Mark('1');
    std::cout << "~After~" << std::endl;
    test->Print();
}
// ---------------------------------------------------------------------
// Tests all the functions related to the State Class
// No preconditions
// Prints the state of each test object
void
TestStateFunctions(){
    std::cout << "Testing the State class from Square-KorideMok.hpp" << std::endl;
    std::cout << "Expected Output:" << std::endl;
    std::cout << "1. Null values" << std::endl;
    std::cout << "2. Empty markable State" << std::endl;
    std::cout << "3. Numbered unmarkable State" << std::endl;
    std::cout << "4. Unmarked State with limited possibilities\n" << std::endl;


    std::cout << "1. Null Value Test" << std::endl;
    State* objOne = new State();
    PrintTestCase(objOne);
    objOne->~State();
    std::cout << std::endl;

    std::cout << "2. Empty State Test" << std::endl;
    State* objTwo = new State('-');
    PrintTestCase(objTwo);
    objTwo->~State();
    std::cout << std::endl;

    std::cout << "3. Fixed State Test" << std::endl;
    State* objThree = new State('9');
    PrintTestCase(objThree);
    objThree->~State();
    std::cout << std::endl;

    std::cout << "4. Limited Possibilities Test" << std::endl;
    State* objFour = new State('~');
    PrintTestCase(objFour);
    objFour->~State();
    std::cout << std::endl;
}