#include "game.hpp"

Game::Game(string filename){
    ifs.open(filename);
    char x;
    ifs>>x;
    if (ifs.is_open()){
        cout<<"Success"<<endl;
        cout<<x;
    }
    else {
        cout << "Failure" << endl;
    }
    ifs.close();
}

void Game::run(){
    string legal_menu;
    char cstring[] {"MURSQ"};
    menu_c("Menu", 6, menu_options, cstring);
    }


