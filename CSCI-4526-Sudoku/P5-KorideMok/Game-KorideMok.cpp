// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Game-KorideMok.hpp"

// ---------------------------------------------------------------------
// Game Constructor
// Precondition: A valid game file exists
// Postcondition: Game object is created
Game::
Game(ifstream& file) : file(file){
    string types = "TtDdSs";
    file>>gameType;
    if (types.find(gameType) == string::npos) fatal("Invalid Game Type");
    switch(toupper(gameType)){
        case 'T': n = 9; break;
        case 'D': n = 9; break;
        case 'S': n = 6; break;
    }
    puzzle = new Board(n, file);
}


// ---------------------------------------------------------------------
// Runs the game
// Precondition: Game object exists
// Postcondition: Displays the menu and calls possible options until quit is called
void Game::
run(){
    char legalMenu[] { "MmUuRrSsQq" };
    for(;;){
        cout <<"\nWhat Would You Like To Do? " <<endl;
        char x = menu_c("Menu", 6, menu, legalMenu);
        switch (toupper(x)) {
            case 'M':
                short r, c;
                char value;
                cout <<"Input 'Row' 'Column' 'Value': ";
                cin >> r >> c >> value;
                puzzle->mark(r, c, value);
                continue;
            case 'U': continue;
            case 'R': continue;
            case 'S': continue;
            case 'Q': return;
        }
    }
}


