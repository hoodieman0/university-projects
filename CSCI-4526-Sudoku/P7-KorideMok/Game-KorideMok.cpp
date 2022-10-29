// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Game-KorideMok.hpp"

const char* Game::
menu[7] = {"Print", "Mark", "Undo", "Redo", "Save", "Restore", "Quit"};

// ---------------------------------------------------------------------
// Game Constructor
// Precondition: A valid game file exists
// Postcondition: Game object is created
Game::
Game(string filename) {
    try{
        file.open(filename);
        if (!file.is_open()) throw StreamException();//fatal("!Could Not Open Game File!");
        char x;
        file>>x;

        string types = "TtDdSs";
        if (types.find(x) == string::npos) throw InvalidChar(x);

        gameType = x;
        int size = 9;
        int clstr = 27;
        switch(tolower(gameType)){
            case 't': puzzle = new Board(size, clstr, file); break;
            case 'd': clstr = 29; puzzle = new DiagBoard(size, clstr, file); break;
            case 's': size = 6; break;
            default: throw StreamException(); //fatal("!Invalid Game Type!");
        }
    }
    catch (Exception& e){
        cerr << e << endl;
        fatal("Could Not Create Game Object");
    }

}



// ---------------------------------------------------------------------
// Runs the game
// Precondition: Game object exists
// Postcondition: Displays the menu and calls possible options until quit is called
void Game::
run(){
    char legal[] {"PMURSQ"};
    for(;;){
        cout <<"\nWhat Would You Like To Do? " <<endl;
        char x = menu_c("Menu", 6, menu, legal);
        switch (toupper(x)) {
            case 'P': cout <<*puzzle <<endl; continue; //TODO see if print is necessary
            case 'M':
                short r, c;
                char value;
                cout <<"Input Row: ";
                cin >> r;
                cout <<"Input Column: ";
                cin >> c;
                cout <<"Input Value: ";
                cin >> value;
                try{
                    puzzle->mark(r, c, value);
                }
                catch(Exception& e){
                    cout << e << endl;
                }

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


