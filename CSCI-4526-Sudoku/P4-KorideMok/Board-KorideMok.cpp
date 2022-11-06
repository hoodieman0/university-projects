// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Board-KorideMok.hpp"

// ---------------------------------------------------------------------
// Constructor for Board
// Preconditions: Game object exists
// Postconditions: Board object is created
Board::
Board(short n, ifstream& file) : n(n), file(file), left(n*n) {
    bd = new Square[n*n];
    getPuzzle();
    cout << "~Creating Board~" <<endl;
}

// ---------------------------------------------------------------------
// Reads the ifstream to create initialize squares
// Preconditions: ifstream has valid file
// Postconditions: bd is filled with Square objects reflecting file
void Board::
getPuzzle() {
    char x;
    string types = "123456789-";

    //depends on initial char being read already
    for (short r = 0; r < n; r++){
        file.get(x); //discard newline
        for (short c = 0; c < n; c++){
            file.get(x);
            cerr << x;
            if (types.find(x) == string::npos) fatal("INVALID CHARACTER IN FILE");
            sub(r, c) = Square(x, r ,c);
            if (x != '-') left--;
            }
        }
    x = file.get(); //is the eof check necessary?
    if (file.eof()) return;
}

// ---------------------------------------------------------------------
// Prints the state of the board
// Preconditions: Game object exists, getPuzzle has been run
// Postconditions: All squares and their values of the board are outputted
ostream& Board::
print(ostream& out) {
    for (int j = 0; j < n*n; j++){
        out <<" " <<bd[j] <<"\n ";
        if ((j+1) % 9 == 0) out << "\n";
    }
    return out;
}