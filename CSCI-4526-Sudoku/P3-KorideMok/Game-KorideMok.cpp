#include "Game-KorideMok.hpp"

const char* Game::
menu[6] = {"Mark", "Undo", "Redo", "Save", "Restore", "Quit"};

// ---------------------------------------------------------------------
// Game Constructor
// Precondition: A valid game file exists
// Postcondition: Game object is created
Game::
Game(string filename){ //TODO change from string to ifstream
    file.open(filename); //TODO file validation in main,
    if (file.is_open()){
        char x;
        file>>x;

        string types = "TtDdSs"; //TODO change P2
        if (types.find(x)) {
            gameType = x;
        }
        else{
            fatal("!Invalid Game Type!");
        }
    }
    else {
        fatal("!Could Not Open Game File!");
    }
    file.close(); //TODO change this
}


// ---------------------------------------------------------------------
// Runs the game
// Precondition: Game object exists
// Postcondition: Displays the menu and calls possible options until quit is called
void Game::
run(){
    char legal_menu[] {"MURSQ"}; //TODO please make camelCase and shorter
    for(;;){
        cout <<"\nWhat Would You Like To Do? " <<endl;
        char x = menu_c("Menu", 6, menu, legal_menu);
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


