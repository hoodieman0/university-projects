// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Square-KorideMok.hpp"
#include "Cluster-KorideMok.hpp"

// ---------------------------------------------------------------------
// Prints the values of the Square object in a human-readable format
// Preconditions: Square object exists
// Postconditions: Prints Square's variables to the console
Square::
Square(char input, short r, short c) : info(input), row(r), col(c){
    //cout <<"Constructing Square [" <<row << ", " <<col <<"]" <<endl;
}

// ---------------------------------------------------------------------
// Changes the value of square
// Preconditions: Square object exists
// Postconditions: if marker is in legal, value = marker, else no change
void Square::
mark(char marker){
    string legal = "123456789";
    if(legal.find(marker) == string::npos) { cout <<"Invalid Input" <<endl; return; }
    info.mark(marker);
    shoop(marker);
}

void Square::
shoop(char val) {
    for (Cluster* cl : buddies) { cl->shoop(val); }
}

void Square::turnOff(int n) {
    short mask = 0x000;
    switch(n){
        case 1: mask = 0x002; break; //inverse = 0011 1111 1100
        case 2: mask = 0x004; break; //inverse = 0011 1111 1010
        case 3: mask = 0x008; break; //inverse = 0011 1111 0110
        case 4: mask = 0x010; break; //inverse = 0011 1110 1110
        case 5: mask = 0x020; break; //inverse = 0011 1101 1110
        case 6: mask = 0x040; break; //inverse = 0011 1011 1110
        case 7: mask = 0x080; break; //inverse = 0011 0111 1110
        case 8: mask = 0x100; break; //inverse = 0010 1111 1110
        case 9: mask = 0x200; break; //inverse = 0001 1111 1110
        default:
            fatal("!WRONG MARKER IN Square::turnOff!");
    }
    mask = ~mask;
    info.turnOff(mask);
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