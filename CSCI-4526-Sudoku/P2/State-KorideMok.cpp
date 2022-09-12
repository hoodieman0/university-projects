// Written by James Mok and Niel Koride

#include "State-KorideMok.hpp"

// ---------------------------------------------------------------------
// State Constructor
// Precondition: None
// Postcondition: State object is created
State::
State(char startingValue){
    value = startingValue;
    //unit test value
    if (startingValue == '~'){
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
        cerr <<"Cannot Add Value" <<endl;   //TODO change possibilities with this
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

    short temp = possibilities >> 1;
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
