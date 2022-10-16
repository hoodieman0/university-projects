// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Square-KorideMok.hpp"
#include "Cluster-KorideMok.hpp"

// ---------------------------------------------------------------------
// Prints the values of the Square object in a human-readable format
// Preconditions: Square object exists
// Postconditions: Prints Square's variables to the console
Square::
Square(char input, short r, short c) : State(input), row(r), col(c){
    //cout <<"Constructing Square " <<row << ", " <<col <<endl;
}

// ---------------------------------------------------------------------
// Changes the value of square's state
// Preconditions: Square object exists
// Postconditions: if marker is in legal and not in another cluster, value = marker, else no change
void Square::
mark(char marker){
    string legal = "123456789";
    if (legal.find(marker) == string::npos) { cout <<"!Invalid Input!" <<endl; return; }

    for (Cluster* cl : buddies) {
        if (!cl->isValid(marker)) {
            cout <<marker <<" is already in this cluster!" <<endl;
            return; }
    }
    shoop(marker);
    markState(marker);
}

// ---------------------------------------------------------------------
// Turns off the val bit for every square in each cluster
// Preconditions: Square object has valid cluster objects
// Postconditions: Cluster::shoop is called: val bit turned off for each square in the three clusters
void Square::
shoop(char val) {
    for (Cluster* cl : buddies) { cl->shoop(val); }
}

// ---------------------------------------------------------------------
// Turns of the n bit in this square
// Preconditions: square object exists
// Postconditions: calls State::turnOffBit: n bit is turned off for this square
void Square::turnOff(int n) {
    short mask = 0x001;
    mask = mask << n;
    mask = ~mask;
    turnOffBit(mask);
}

// ---------------------------------------------------------------------
// Prints the values of the Square object in a human-readable format
// Preconditions: Square object exists
// Postconditions: Prints Square's variables to the console
ostream& Square::
printSquare(ostream& out){
    out <<"Square [" <<row+1 <<", " <<col+1 <<"] ";//State;
    printState(out);
    return out;
}