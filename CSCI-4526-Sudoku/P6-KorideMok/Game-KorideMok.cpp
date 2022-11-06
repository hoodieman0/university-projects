// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Game-KorideMok.hpp"

// ---------------------------------------------------------------------
// Game Constructor
// Precondition: A valid game file exists
// Postcondition: Game object is created
Game::
Game(ifstream& file) : file(file) {
    short clstr;
    string types = "TtDdSs";
    file>>gameType;
    if (types.find(gameType) == string::npos) fatal("Invalid Game Type");
    switch(tolower(gameType)){
        case 't': n = 9; clstr = 27; puzzle = new Board(n, clstr, file); break;
        case 'd': n = 9; clstr = 29; puzzle = new DiagBoard(n, clstr, file); break;
        case 's': n = 6; clstr = 18; puzzle = new Board(n, clstr, file); break;
    }
}



// ---------------------------------------------------------------------
// Runs the game
// Precondition: Game object exists
// Postcondition: Displays the menu and calls possible options until quit is called
void Game::
run(){
    char legal[] {"PpMmUuRrSsQq"};
    for(;;){
        cout <<"\nWhat Would You Like To Do? " <<endl;
        char x = menu_c("Menu", 7, menu, legal);
        switch (toupper(x)) {
            case 'P': cout <<*puzzle <<endl; continue;
            case 'M':
                short r, c;
                char value;
                cout <<"Input 'Row' 'Column' 'Value': ";
                cin >> r >> c >> value;
                puzzle->mark(r, c, value);
                continue; //continues the for loop
            case 'U': continue;
            case 'R': continue;
            case 'S': continue;
            case 'Q': return;
        }
    }
}


