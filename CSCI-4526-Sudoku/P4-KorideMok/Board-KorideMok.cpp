// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Board-KorideMok.hpp"

// ---------------------------------------------------------------------
// Constructor for Board
// Preconditions: Game object exists
// Postconditions: Board object is created
Board::
Board(int n, ifstream& puzfile) : n(n), file(puzfile) {
    cout << "~Creating Board~" <<endl;
}

// ---------------------------------------------------------------------
// Constructor for Board
// Preconditions: Game object exists
// Postconditions: Board object is created
void Board::
getPuzzle() {
    char x;
    string types = "123456789-";
    for (int j = 0; j < n; j++){
        for (int k = 0; k < n; k++){
            file >> x;
            if (types.find(x)){
                Square temp(x, j, k);

            }
        }

    }
}

// ---------------------------------------------------------------------
// Prints the state of the board
// Preconditions: Game object exists, getPuzzle has been run
// Postconditions: All squares and their values of the board are outputted
ostream& Board::
print(ostream& out) {
    for (int j = 0; j < n*n; j++){
        out <<" " <<bd[j] <<" ";
        if (j % 9 == 0){ //TODO make sure this works
            out << "\n";
        }
    }
    return out;
}