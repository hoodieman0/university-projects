// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Game-KorideMok.hpp"

const char* Game::
menu[6] = {"Mark", "Undo", "Redo", "Save", "Restore", "Quit"};

// ---------------------------------------------------------------------
// Game Constructor
// Precondition: A valid game file exists
// Postcondition: Game object is created
Game::
Game(string filename) {
    file.open(filename);
    if (file.is_open()){
        char x;
        file>>x;

        string types = "TtDdSs"; //TODO change P2
        if (types.find(x)) {
            gameType = x;
            int n;
            switch(tolower(gameType)){
                case 't': n = 9; break;
                case 'd': n = 9; break;
                case 's': n = 6; break;
                default: fatal("!Invalid Game Type!");
            }
            Board temp(n, file);
            puzzle = &temp;
        }
        else{ fatal("!Invalid Game Type!"); }
    }
    else { fatal("!Could Not Open Game File!"); }
}


// ---------------------------------------------------------------------
// Runs the game
// Precondition: Game object exists
// Postcondition: Displays the menu and calls possible options until quit is called
void Game::
run(){
    char legal[] {"MURSQ"};
    for(;;){
        cout <<"\nWhat Would You Like To Do? " <<endl;
        char x = menu_c("Menu", 6, menu, legal);
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
                //puzzle->mark(r, c, value);
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


