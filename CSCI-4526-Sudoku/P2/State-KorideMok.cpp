// Written by James Mok and Neelakanta Bharadwaj Koride

#include "State-KorideMok.hpp"

// ---------------------------------------------------------------------
// State Constructor
// Precondition: None
// Postcondition: State object is created
State::
State(char input){
    value = input;
    //unit test value
    if (input == '~'){
        poslist = 0x0f2;
        fixed = false;
        value = '-';
    }
    else if (input != '-'){
        poslist = 0x000;
        fixed = true;
    }
}

// ---------------------------------------------------------------------
// Marks the State object with a valid character
// Precondition: State object exists
// Postcondition: Changes State variable "value" to the given character
// Failure: "Cannot Add Value"
void State::
mark(char ch){
    if (!this->fixed){
        value = ch;
    }
    else{
        cout <<"Cannot Add Value" <<endl;   //TODO change poslist with this
    }
}

// ---------------------------------------------------------------------
// Prints the variables of the State object in a human-readable format
// Preconditions: State object exists
// Postconditions: Prints State's variables to the console
void const State::
print( ostream& out ){
    out <<"value: " <<value <<" fixed: " <<boolalpha <<fixed;
    out <<" possibilities: ";

    short temp = poslist >> 1;
    short mask = 0x001;
    for (int counter = 1; counter <= 9; counter++){
        if ((temp & mask) == 1){
            out << counter;
        }
        else{
            out <<'-';
        }

        temp = temp >> 1;
    }
    out <<endl;
}
