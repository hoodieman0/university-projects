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
            case 'M': Mark(); NewMove(); continue; //continues the for loop
            case 'T': TurnOff(); NewMove(); continue;
            case 'U': continue;
            case 'R': continue;
            case 'S': continue;
            case 'E': continue;
            case 'Q': return;
        }
    }
}

void Game::
Mark(){
    short r, c;
    char value;
    cout <<"Input 'Row' 'Column' 'Value': ";
    cin >> r >> c >> value;
    try{ puzzle->mark(r, c, value); }
    catch(GameException& e) { cout <<e << endl; }


}

void Game::
TurnOff(){
    short r, c;
    char value;
    cout <<"Input 'Row' 'Column' 'Value': ";
    cin >> r >> c >> value; 
    puzzle->sub(r, c).turnOff(value - '0');
}

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

