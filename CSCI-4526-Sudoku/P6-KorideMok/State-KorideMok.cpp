// Written by James Mok and Neelakanta Bharadwaj Koride

#include "State-KorideMok.hpp"

// ---------------------------------------------------------------------
// State Constructor
// Precondition: None
// Postcondition: State object is created
State::
State(const char input) : value(input){
    if (input != '-'){
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
mark(const char ch){
    if (fixed) cout <<"Cannot Mark A Fixed Value" <<endl;
    value = ch;
    poslist = 0;
}

// ---------------------------------------------------------------------
// Prints the variables of the State object in a human-readable format
// Preconditions: State object exists
// Postconditions: Prints State's variables to the ostream
ostream& State::
print(ostream& out) const{
    out <<"value: " <<value <<" fixed: " <<boolalpha <<fixed;
    out <<" possibilities: ";

    short temp = poslist >> 1;
    short mask = 0x001;
    for (int counter = 1; counter <= 9; counter++){
        if ((temp & mask) == 1){ out << counter; }
        else{ out <<'-';}
        temp = temp >> 1;
    }
    return out;
}