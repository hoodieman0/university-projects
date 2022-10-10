// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Board-KorideMok.hpp"

static const string clusterTypes[3] = {"row", "col", "box"};

// ---------------------------------------------------------------------
// Constructor for Board
// Preconditions: Game object exists
// Postconditions: Board object is created
Board::
Board(int n, ifstream& puzfile) : n(n), file(puzfile), left(n*n) {
    bd = new Square[n*n];
    getPuzzle();
    makeClusters();
    cout << "~Creating Board~" <<endl;
}

// ---------------------------------------------------------------------
// Reads the ifstream to create initialize squares
// Preconditions: ifstream has valid file
// Postconditions: bd is filled with Square objects reflecting file
void Board::
getPuzzle() {
    char x;
    string line;
    int index = 0;
    string types = "123456789-";

    for (int j = 0; j < n; j++){
        file >> line; //does not account for beginning gameType char
        for (int k = 0; k < n; k++){
            x = line[k];
            if (types.find(x) != -1){
                Square temp(x, j, k);
                bd[index] = temp;
                index++;

                if (x != '-'){ left--; }
            }
            else { fatal("!INVALID CHARACTER IN FILE!"); }
        }
    }
}

void Board::
mark(int r, int c, char value) {
    sub(r, c).mark(value);
}

void Board::
makeClusters() {
    Square* arr[9];

    for (short k = 1; k < 10; k++) {
        createRow(k);
        Cluster* a(ClusterType::ROW, arr);
        buddies.push_back(a);
    }
}

void Board::
createRow(short r) {
    for (short c = 0; c < 9; c++) { sub(r, c); }
}

void Board::
createCol(short c) {

}

void Board::
createBox(short r, short c) {

}

// ---------------------------------------------------------------------
// Prints the state of the board
// Preconditions: Game object exists, getPuzzle has been run
// Postconditions: All squares and their values of the board are outputted
ostream& Board::
print(ostream& out) {
    for (int j = 0; j < n*n; j++){
        out <<" " <<bd[j] <<"\n ";
        if ((j+1) % 9 == 0){
            out << "\n";
        }
    }
    return out;
}