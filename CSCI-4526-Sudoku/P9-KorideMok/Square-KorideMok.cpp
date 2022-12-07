// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Square-KorideMok.hpp"
#include "Cluster-KorideMok.hpp"

// ---------------------------------------------------------------------
// Prints the values of the Square object in a human-readable format
// Preconditions: Square object exists
// Postconditions: Prints Square's variables to the console
Square::
Square(const char input, const short r, const short c) : State(input), row(r), col(c){
}

// ---------------------------------------------------------------------
// Changes the value of square's state
// Preconditions: Square object exists
// Postconditions: if marker is in legal and not in another cluster, value = marker, else no change
void Square::
mark(const char marker){
    string legal = "123456789";
    if (legal.find(marker) == string::npos) throw InvalidMarkerException(marker);

    if (fixed) throw MarkFixedException(row+1, col+1);

    for (Cluster* cl : buddies) {
        if (!cl->isValid(marker)) throw ExistingValueException(marker, row+1, col+1);
    }

    shoop(marker);
    value = marker;
    posList = 0;
}

// ---------------------------------------------------------------------
// Turns off the val bit for every square in each cluster
// Preconditions: Square object has valid cluster objects
// Postconditions: Cluster::shoop is called: val bit turned off for each square in the three clusters
void Square::
shoop(const char val) { //does not need input validation because mark() takes care of it
    for (Cluster* cl : buddies) cl->shoop(val);
}

// ---------------------------------------------------------------------
// Turns of the n bit in this square
// Preconditions: square object exists
// Postconditions: calls State::turnOffBit: n bit is turned off for this square
void Square::
turnOff(const int n) {
    short mask = 0x001;
    mask = mask << n;
    mask = ~mask;
    posList = posList & mask;
}

// ---------------------------------------------------------------------
// Sets all the values of the state to the newState
// Preconditions: square object exists
// Postconditions: State posList, value, fixed are changed 
void Square::
setState(State newState){
    posList = newState.getPosList();
    value = newState.getValue();
    fixed = newState.getFixed();
}

// ---------------------------------------------------------------------
// Prints the values of the Square object in a human-readable format
// Preconditions: Square object exists
// Postconditions: Prints Square's variables to the console
ostream& Square::
print(ostream& out) const{
    out <<"Square [" <<row+1 <<", " <<col+1 <<"] ";
    State::print(out);
    return out;
}