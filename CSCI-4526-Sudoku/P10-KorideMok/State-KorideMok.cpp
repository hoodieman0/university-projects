// Written by James Mok and Neelakanta Bharadwaj Koride

#include "State-KorideMok.hpp"

// ---------------------------------------------------------------------
// State Constructor
// Precondition: None
// Postcondition: State object is created
State::
State(const char input) : value(input){
    if (input != '-'){
        posList = 0x000;
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
    if (fixed) throw MarkFixedException();
    value = ch;
    posList = 0;
}

// ---------------------------------------------------------------------
// Returns the posList variable in a human readable format
// Precondition: State object exists
// Postcondition: returns a string where each char is whether the number exists
string State::getPosList() const{
    short list = posList >> 1;

    string s;
    short mask = 0x001;
    for (int counter = 1; counter <= 9; counter++){
        if ((list & mask) == 1){ s += counter + 48; }
        else{ s += '-'; }
        list = list >> 1;
    }
    return s;
}

// ---------------------------------------------------------------------
// Prints the variables of the State object in a human-readable format
// Preconditions: State object exists
// Postconditions: Prints State's variables to the ostream
ostream& State::
print(ostream& out) const{
    out <<"value: " <<value <<" fixed: " <<boolalpha <<fixed;
    out <<" possibilities: ";

    short temp = posList >> 1;
    short mask = 0x001;
    for (int counter = 1; counter <= 9; counter++){
        if ((temp & mask) == 1){ out << counter; }
        else{ out <<'-';}
        temp = temp >> 1;
    }
    return out;
}