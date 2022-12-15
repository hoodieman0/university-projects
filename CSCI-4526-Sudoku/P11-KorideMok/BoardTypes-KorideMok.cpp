// Written by James Mok

#include "BoardTypes-KorideMok.hpp"

static const string clusterT[4] = {"ROW", "COLUMN", "BOX", "DIAGONAL"};

// ---------------------------------------------------------------------
// Constructor for TradBoard
// Preconditions: Game object exists
// Postconditions: creates a TradBoard object
TradBoard::
TradBoard(short n, short clstr, ifstream& file) : Board(n, clstr, file){
    for (short k = 1; k < 10; k = k + 3) {
        for(short h = 1; h < 10; h = h + 3){
            createBox(k, h);
        }
    }
}

// ---------------------------------------------------------------------
// Helper function for TradBoard, creates the clusters that are boxes
// Preconditions: TradBoard() has been run
// Postconditions: the cluster for the Square [r, c] is created and put into buddies
void TradBoard::
createBox(const short r, const short c) {
    Square* arr[9];
    short index = 0;
    for (short k = r; k < r + 3; k++) {
        for (short h = c; h < c + 3; h++) { arr[index] = &sub(k, h); index++; }
    }

    Cluster* temp = new Cluster(clusterT[(int)ClusterType::BOX], arr);
    buddies.push_back(temp);
}


// ---------------------------------------------------------------------
// Constructor for DiagBoard
// Preconditions: Game object exists
// Postconditions: creates a DiagBoard object
DiagBoard::
DiagBoard(short n, short clstr, ifstream& file) : TradBoard(n, clstr, file) {
    //Is knowing the amount of clusters important if I am making a diagonal board?
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


SixyBoard::
SixyBoard(short n, short clstr, ifstream& file) : Board(n, clstr, file){
    for (int r = 1; r < 5; r = r + 3){
        for (int c = 1; c < 7; c = c + 2){
            createVertBox(r, c);
        }
    }
    for (int r = 1; r < 7; r = r + 2){
        for (int c = 1; c < 5; c = c + 3){
            createHorBox(r, c);
        }
    }
}

void SixyBoard::
createVertBox(int row, int col){
    Square* arr[6];
    int index = 0;
    for (int r = row; r < row + 3; r++){
        for (int c = col; c < col + 2; c++){arr[index] = &sub(r, c); index++; }
    }
    
    if (index > 6) cerr <<"Boxing went wrong" <<endl;

    Cluster* temp = new Cluster(clusterT[(int)ClusterType::BOX], arr);
    buddies.push_back(temp);
}

void SixyBoard::
createHorBox(int row, int col){
    Square* arr[6];
    int index = 0;
    for (int r = row; r < row + 2; r++){
        for (int c = col; c < col + 3; c++){arr[index] = &sub(r, c); index++; }
    }

    Cluster* temp = new Cluster(clusterT[(int)ClusterType::BOX], arr);
    buddies.push_back(temp);
}