// Written by James Mok and Neelakanta Bharadwaj Koride

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

void Square::
mark(char marker){
    short mask = 0x000;
    switch(marker){
        case '1': mask = 0x002; break; //inverse = 0011 1111 1100
        case '2': mask = 0x004; break; //inverse = 0011 1111 1010
        case '3': mask = 0x008; break; //inverse = 0011 1111 0110
        case '4': mask = 0x010; break; //inverse = 0011 1110 1110
        case '5': mask = 0x020; break; //inverse = 0011 1101 1110
        case '6': mask = 0x040; break; //inverse = 0011 1011 1110
        case '7': mask = 0x080; break; //inverse = 0011 0111 1110
        case '8': mask = 0x100; break; //inverse = 0010 1111 1110
        case '9': mask = 0x200; break; //inverse = 0001 1111 1110
        case '-': break;
        default:
            cerr <<"Cannot Mark Square With: " <<marker;
    }
    mask = (~mask);

    info.mark(marker, mask);
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