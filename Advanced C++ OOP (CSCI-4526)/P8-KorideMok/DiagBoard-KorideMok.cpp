// Written by James Mok

#include "DiagBoard-KorideMok.hpp"

static const string clusterT[4] = {"ROW", "COLUMN", "BOX", "DIAGONAL"};

// ---------------------------------------------------------------------
// Constructor for DiagBoard
// Preconditions: Game object exists
// Postconditions: creates a DiagBoard object
DiagBoard::
DiagBoard(short n, short clstr, ifstream& file) : Board(n, clstr, file) {
    //Is knowing the amount of clusters important if I am making a diagonal board?
    cout << "~Adding Diagonals~" <<endl;
    createDiagonal();
}

// ---------------------------------------------------------------------
// Creates the diagonal clusters for a diagonal board
// Preconditions: Board object exists
// Postconditions: adds two diagonal clusters to buddies
void DiagBoard::
createDiagonal() {
    Square* topArr[9];
    Square* botArr[9];
    for (int row = 0; row < 9; row++) {
        topArr[row] = &sub(row+1, row+1);
        botArr[row] = &sub(row+1, 9-row);
    }
    Cluster* tempOne = new Cluster(clusterT[(int)ClusterType::DIAGONAL], topArr);
    Cluster* tempTwo = new Cluster(clusterT[(int)ClusterType::DIAGONAL], botArr);
    Board::buddies.push_back(tempOne);
    Board::buddies.push_back(tempTwo);
}