// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Square-KorideMok.hpp"

// ---------------------------------------------------------------------
// Prints the values of the Square object in a human-readable format
// Preconditions: Square object exists
// Postconditions: Prints Square's variables to the console
Square::
Square(char input, short r, short c) : info(input), row(r), col(c){
    //cout <<"Constructing Square " <<row << ", " <<col <<endl;
}

void Square::
mark(char marker){
    string temp(1,marker);
    string valid = "123456789";
    if(valid.find(marker)) {
        info.mark(marker);
    }
    else{ cout <<"Invalid Input" <<endl; }
}

// ---------------------------------------------------------------------
// Prints the values of the Square object in a human-readable format
// Preconditions: Square object exists
// Postconditions: Prints Square's variables to the console
ostream& Square::
print(ostream& out){
    out <<"Square [" <<row+1 <<", " <<col+1 <<"] " << info;
    return out;
}