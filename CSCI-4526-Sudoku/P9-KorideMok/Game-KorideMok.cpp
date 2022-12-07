// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Game-KorideMok.hpp"

const string Game::
menu[7] = { "Mark", "Turn Off", "Undo", "Redo", "Save", "rEstore", "Quit"};

// ---------------------------------------------------------------------
// Game Constructor
// Precondition: A valid game file exists
// Postcondition: Game object is created
Game::
Game(ifstream& file) : file(file) {
    short clstr;
    const static string types = "TtDdSs";
    file>>gameType;
    if (types.find(gameType) == string::npos) throw InvalidGameTypeException(gameType);
    switch(toupper(gameType)){
        case 'T': n = 9; clstr = 27; puzzle = new Board(n, clstr, file);
        case 'D': n = 9; clstr = 29; puzzle = new DiagBoard(n, clstr, file); break;
        case 'S': n = 6; clstr = 18; puzzle = new Board(n, clstr, file); break;
    }
}



// ---------------------------------------------------------------------
// Runs the game
// Precondition: Game object exists
// Postcondition: Displays the menu and calls possible options until quit is called
void Game::
run(){
    const static char legal[] { "MmTtUuRrSsEeQq" };
    Viewer fancyView(9, 9, *puzzle);
    
    for(;;){
        fancyView.show(cout);
        cout <<"\nWhat Would You Like To Do? " <<endl;
        char x = menu_c("Menu", 7, menu, legal);
        switch (toupper(x)) {
            case 'M': Mark(); continue; //continues the for loop
            case 'T': TurnOff(); continue;
            case 'U': Undo(); continue;
            case 'R': Redo(); continue;
            case 'S': continue;
            case 'E': continue;
            case 'Q': return;
        }
    }
}

// ---------------------------------------------------------------------
// Helper function for Game::run() to mark a square
// Precondition: Game object exists
// Postcondition: Marks the row r and column c with the given value
// Fail Condition: The inputted value is in the cluster
void Game::
Mark(){
    short r, c;
    char value;
    cout <<"Input 'Row' 'Column' 'Value': ";
    cin >> r >> c >> value;
    try{ puzzle->mark(r, c, value); }
    catch(GameException& e) { cout <<e << endl; return; }
    NewMove();
}

// ---------------------------------------------------------------------
// Helper function for Game::run() to remove a possibility from a square
// Precondition: Game object exists
// Postcondition: Removes the 'value' bit at row r and column c 
void Game::
TurnOff(){
    short r, c;
    char value;
    cout <<"Input 'Row' 'Column' 'Value': ";
    cin >> r >> c >> value; 
    puzzle->sub(r, c).turnOff(value - '0');
    NewMove();
}

// ---------------------------------------------------------------------
// Helper function for Game::Mark() and Game::TurnOff() to make a new Frame,
// add the Frame to the undo stack, and clear the redo stack
// Precondition: Game object exists
// Postcondition: undo stack has a new Frame*, redo stack has no values
void Game::
NewMove(){
    State arr[81];
    for (int row = 0; row < n; row++){
        for (int col = 0; col < n; col++){
            arr[row+col] = puzzle->sub(row+1, col+1);
        }
    }

    Frame* frame = new Frame(arr);
    undo.push(frame);
    redo.zap();
}

// ---------------------------------------------------------------------
// Helper function for Game::run() to go back to a previous Frame
// Precondition: Game object exists
// Postcondition: Board::restoreState() is called -> all Squares have their
//                states changed
void Game::
Undo(){
    if (undo.size() < 2) { cout <<"Not Enough Moves Has Been Made!" <<endl; return; }

    Frame* frame = undo.top();
    undo.pop();
    redo.push(frame);

    puzzle->restoreState(frame);
}

// ---------------------------------------------------------------------
// Helper function for Game::run() to redo a previous Frame
// Precondition: Game object exists
// Postcondition: Board::restoreState() is called -> all Squares have their
//                states changed
void Game::
Redo(){
    if (redo.size() == 0) { cout <<"No Moves To Redo!" <<endl; return; }

    Frame* frame = redo.top();
    redo.pop();
    undo.push(frame);

    puzzle->restoreState(frame);
}