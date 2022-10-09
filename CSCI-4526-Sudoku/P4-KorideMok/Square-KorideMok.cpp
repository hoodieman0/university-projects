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

// ---------------------------------------------------------------------
// Changes the value of square
// Preconditions: Square object exists
// Postconditions: if marker is in legal, value = marker, else no change
void Square::
mark(char marker){

    string legal = "123456789";
    int result = legal.find(marker);
    if (result == string::npos) cout <<"Invalid Input" <<endl;
    else info.mark(marker);
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