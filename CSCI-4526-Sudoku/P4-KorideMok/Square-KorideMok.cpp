// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Square-KorideMok.hpp"
#include <regex> //used in mark

// ---------------------------------------------------------------------
// Prints the values of the Square object in a human-readable format
// Preconditions: Square object exists
// Postconditions: Prints Square's variables to the console
Square::
Square(char input, short r, short c) : info(input), row(r), col(c){
    cout <<"Constructing Square [" <<row << ", " <<col <<"]" <<endl;
}

void Square::
mark(char marker){
    string legal = "123456789";
    if(legal.find(marker) == string::npos) { cout <<"Invalid Input" <<endl; return; }
    info.mark(marker);
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