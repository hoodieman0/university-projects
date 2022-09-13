// Written by James Mok and Niel Koride

#include "Square-KorideMok.hpp"
#include <iostream>

// ---------------------------------------------------------------------
// Default Constructor for Square objects
// No precondition
// Postconiditon: Null value square object is created
Square::Square(){
    std::cout << "Default Constructor" << std::endl;
    value = '\0';
    fixed = false;
    possibilities = 0;
}

// ---------------------------------------------------------------------
// Square Constructor
// No precondition
// Postcondition: Square object is created
Square::Square(char startingValue){
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
// Square Destructor
// Precondition: Square object exists
// Postcondition: Deletes Square object
Square::~Square(){
    std::cout << "Default Destructor" << std::endl;
}

// ---------------------------------------------------------------------
// Marks the Square object with a valid character
// Precondition: Square object exists
// Postcondition: Changes square variable "value" to the given character
// Failure: "Cannot Add Value"
void
Square::Mark(char ch){
    if (!this->fixed){
        value = ch;
    }
    else{
        std::cout << "Cannot Add Value" << std::endl;
    }
}

// ---------------------------------------------------------------------
// Prints the variables of the Square object in a human-readable format
// Preconditions: Square object exists
// Postconditions: Prints the variables to the console
void
Square::Print(){
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