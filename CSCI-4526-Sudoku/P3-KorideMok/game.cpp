#include "game.hpp"


// ---------------------------------------------------------------------
// Game Constructor
// Precondition: A valid game file exists
// Postcondition: Game object is created
Game::
Game(string filename){
    file.open(filename);
    if (file.is_open()){
        char x;
        file>>x;

        string types = "TtDdSs";
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
    file.close();
}


// ---------------------------------------------------------------------
// Runs the game
// Precondition: Game object exists
// Postcondition: Displays the menu and calls possible options until quit is called
void Game::
run(){
    char legal_menu[] {"MURSQ"};
    for(;;){
        cout <<"What Would You Like To Do? " <<endl;
        menu_c("Menu", 6, menu, legal_menu);
    }
}


