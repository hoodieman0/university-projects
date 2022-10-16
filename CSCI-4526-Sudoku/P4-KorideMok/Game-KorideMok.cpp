// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Game-KorideMok.hpp"

const string Game::
menu[6] = {"Mark", "Undo", "Redo", "Save", "Restore", "Quit"};

// ---------------------------------------------------------------------
// Game Constructor
// Precondition: A valid game file exists
// Postcondition: Game object is created
Game::
Game(char* filename){
    file.open(filename);
    if (!file.is_open()) fatal("!Could Not Open Game File!");

    string types = "TtDdSs";
    char x;
    file>>x;
    if (types.find(x) == string::npos) fatal("!Invalid Game Type!");
    gameType = x;
    switch(tolower(gameType)){
        case 't': n = 9; break;
        case 'd': n = 9; break;
        case 's': n = 6; break;
    }

    puzzle = new Board(n, file);
}


// ---------------------------------------------------------------------
// Runs the game
// Precondition: Game object exists
// Postcondition: Displays the menu and calls possible options until quit is called
void Game::
run(){
    char legalMenu[] { "MURSQ" };
    for(;;){
        cout <<"\nWhat Would You Like To Do? " <<endl;
        char x = menu_c("Menu", 6, menu, legalMenu);
        switch (x) {
            case 'M':
                short r, c;
                char value;
                cout <<"Input Row: ";
                cin >> r;
                cout <<"Input Column: ";
                cin >> c;
                cout <<"Input Value: ";
                cin >> value;
                puzzle->mark(r, c, value);
                continue;
            case 'U': continue;
            case 'R': continue;
            case 'S': continue;
            case 'Q': break;
            default: cout<< "Invalid Command" <<endl; continue;
        }
        break;
    }
    cout <<"~Quitting Game~" <<endl;
}


