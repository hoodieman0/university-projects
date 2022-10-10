// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Board-KorideMok.hpp"

static const char* clusterT[3] = {"ROW", "COLUMN", "BOX"};

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
    for (short k = 1; k < 10; k++) {
        createRow(k);
        createCol(k);
    }
    for (short k = 1; k < 10; k = k +3) {
        for(short h = 1; h < 10; h = h + 3){
            createBox(k, h);
        }
    }
}

void Board::
createRow(short r) {
    Square* arr[9];
    for (short c = 0; c < 9; c++) { arr[c] = &sub(r, c+1); }

    Cluster* temp = new Cluster(clusterT[0], arr);
    buddies.push_back(temp);
}

void Board::
createCol(short c) {
    Square* arr[9];
    for (short r = 0; r < 9; r++) { arr[r] = &sub(r+1, c); }

    Cluster* temp = new Cluster(clusterT[1], arr);
    buddies.push_back(temp);
}

void Board::
createBox(short r, short c) {
    Square *arr[9];
    short index = 0;
    for (short k = r; k < r + 3; k++) {
        for (short h = c; h < c + 3; h++) { arr[index] = &sub(k, h); index++; }
    }

    Cluster* temp = new Cluster(clusterT[2], arr);
    buddies.push_back(temp);
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