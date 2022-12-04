// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Board-KorideMok.hpp"

static const string clusterT[3] = {"ROW", "COLUMN", "BOX"};

// ---------------------------------------------------------------------
// Constructor for Board
// Preconditions: Game object exists
// Postconditions: Board object is created
Board::
Board(const short n, const short clstr, ifstream& file) : n(n), file(file), left(n*n) {
    bd = new Square[n*n];
    getPuzzle();
    makeClusters();
}

// ---------------------------------------------------------------------
// Reads the ifstream to create initial squares
// Preconditions: ifstream has valid file
// Postconditions: bd is filled with Square objects reflecting file
void Board::
getPuzzle() {
    char x;
    static const string types = "123456789-";

    //depends on initial char being read already
    for (short r = 0; r < n; r++){
        file>> x; //discard newline
        for (short c = 0; c < n; c++){
            file>> x;
            if (types.find(x) == string::npos) throw InvalidCharException(x, r);
            sub(r+1, c+1) = Square(x, r ,c);
            if (x != '-') left--;
        }
    }
    x = file.get(); //is the eof check necessary?
    if (file.eof()) return;
}

// ---------------------------------------------------------------------
// Creates the associated clusters for each square
// Preconditions: getPuzzle() has been run
// Postconditions: buddies vector is populated with valid clusters
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

// ---------------------------------------------------------------------
// Helper function for createClusters, creates the clusters that are rows
// Preconditions: getPuzzle() has been run
// Postconditions: the cluster at row r is created and put into buddies
void Board::
createRow(const short r) {
    Square* arr[9];
    for (short c = 0; c < 9; c++) { arr[c] = &sub(r, c+1); }

    Cluster* temp = new Cluster(clusterT[(int)ClusterType::ROW], arr);
    buddies.push_back(temp);
}

// ---------------------------------------------------------------------
// Helper function for createClusters, creates the clusters that are columns
// Preconditions: getPuzzle() has been run
// Postconditions: the cluster at column c is created and put into buddies
void Board::
createCol(const short c) {
    Square* arr[9];
    for (short r = 0; r < 9; r++) { arr[r] = &sub(r+1, c); }

    Cluster* temp = new Cluster(clusterT[(int)ClusterType::COLUMN], arr);
    buddies.push_back(temp);
}

// ---------------------------------------------------------------------
// Helper function for createClusters, creates the clusters that are boxes
// Preconditions: getPuzzle() has been run
// Postconditions: the cluster for the box [r, c] is created and put into buddies
void Board::
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
// marks the square at the given position with the inputted value
// Preconditions: Game object exists
// Postconditions: mark the square with the value, if out of bounds throw exception
void Board::
mark(const short r, const short c, const char value) const {
    if (r < 1 || r > n || c < 1 || c > n) throw InvalidPositionException(r, c);
    sub(r, c).mark(value);
}

// ---------------------------------------------------------------------
// Gets the value of the square at the given position
// Preconditions: Game object exists
// Postconditions: return Square::value
char Board::
getMarkChar(int row, int col) const {
    return sub(row, col).getState().getValue();
}

// ---------------------------------------------------------------------
// Changes the state of the Squares of the board
// Warning! The settings of the original board are kept, 
// i.e. you cannot restore a regular board to a diagonal board
// Preconditions: Frame object exists
// Postconditions: All Square States are changed to match the frame
void Board::
restoreState(Frame* frame){
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            sub(row+1, col+1).setState(frame->getState(row+col));
        }
    }
}


// ---------------------------------------------------------------------
// Prints the state of the board
// Preconditions: Game object exists, getPuzzle has been run
// Postconditions: All squares and their values of the board are outputted
ostream& Board::
print(ostream& out) const {
    for (int j = 0; j < n*n; j++){
        out <<" " <<bd[j] <<"\n ";
        if ((j+1) % n == 0){
            out << "\n";
        }
    }

    int k = 1;
    for (Cluster* cl : buddies) {
        out << "Cluster " << k++ << ": " << *cl << endl;
    }

    return out;
}