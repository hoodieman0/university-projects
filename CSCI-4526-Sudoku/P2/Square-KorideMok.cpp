// Written by James Mok and Niel Koride

#include "Square-KorideMok.hpp"

// ---------------------------------------------------------------------
// Constructor for Square
// Preconditions: None
// Postconditions: A square object with a State, row, and column is created
Square::
Square(char input, short r, short c) : info(input)
{
    row = r;
    col = c;
    cout <<"Constructing Square " <<row <<", " <<col <<endl;
}

// ---------------------------------------------------------------------
// Prints the values of the Square object in a human-readable format
// Preconditions: Square object exists
// Postconditions: Prints Square's variables to the console
ostream& Square::
print(ostream& out){
    out <<"Square [" <<row <<", " <<col <<"] ";
    info.print( out );
    return out;
}