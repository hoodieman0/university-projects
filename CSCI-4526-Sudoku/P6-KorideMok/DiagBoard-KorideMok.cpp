// Written by James Mok

#include "DiagBoard-KorideMok.hpp"

static const string clusterT[4] = {"ROW", "COLUMN", "BOX", "DIAGONAL"};

DiagBoard::
DiagBoard(int n, int clstr, ifstream& file) : Board(n, clstr, file) {
    //Is knowing the amount of clusters important if I am making a diagonal board?
    cout << "~Adding Diagonals~" <<endl;
    createDiagonal();
}

void DiagBoard::
createDiagonal() {
    Square* topArr[9];
    Square* botArr[9];
    for (int row = 0; row < 9; row++) {
        topArr[row] = &sub(row+1, row+1);
        botArr[row] = &sub(row+1, 9-row);
    }
    Cluster* tempOne = new Cluster("DIAGONAL", topArr);
    Cluster* tempTwo = new Cluster("DIAGONAL", botArr);
    Board::buddies.push_back(tempOne);
    Board::buddies.push_back(tempTwo);
}