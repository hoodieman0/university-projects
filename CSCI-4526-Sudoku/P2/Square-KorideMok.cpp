// Written by James Mok and Niel Koride

#include "Square-KorideMok.hpp"
#include <iostream>

// ---------------------------------------------------------------------
// Default Constructor for State objects
// No precondition
// Postconiditon: Null value State object is created
State::State(){
    std::cout << "Default Constructor" << std::endl;
    value = '\0';
    fixed = false;
    possibilities = 0;
}

// ---------------------------------------------------------------------
// State Constructor
// No precondition
// Postcondition: State object is created
State::State(char startingValue){
    value = startingValue;
    if (startingValue == '-'){
        possibilities = 0x3FE; //binary: 0011 1111 1110
        fixed = false;
    }
    //unit test value
    else if (startingValue == '~'){
        possibilities = 0x0f2;
        fixed = false;
        value = '-';
    }
    else{
        possibilities = 0x000;
        fixed = true;
    }
}

// ---------------------------------------------------------------------
// State Destructor
// Precondition: State object exists
// Postcondition: Deletes State object
State::~State(){
    std::cout << "Default Destructor" << std::endl;
}

// ---------------------------------------------------------------------
// Marks the State object with a valid character
// Precondition: State object exists
// Postcondition: Changes State variable "value" to the given character
// Failure: "Cannot Add Value"
void
State::Mark(char ch){
    if (!this->fixed){
        value = ch;
    }
    else{
        std::cout << "Cannot Add Value" << std::endl;
    }
}

// ---------------------------------------------------------------------
// Prints the variables of the State object in a human-readable format
// Preconditions: State object exists
// Postconditions: Prints the variables to the console
void
State::Print(){
    std::cout << "value: " << value << std::endl;
    std::cout << "fixed: " << std::boolalpha << fixed << std::endl;
    std::cout << "possibilities: ";

    short temp = possibilities >> 1;
    short mask = 0x001;
    for (int counter = 1; counter <= 9; counter++){
        if ((temp & mask) == 1){
            std::cout << counter;
        }
        else{
            std::cout << '-';
        }

        temp = temp >> 1;
    }
    std::cout << std::endl;
}