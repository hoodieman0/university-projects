#include "game.hpp"
#include "tools.hpp"
#include <iostream>
#include <fstream>

Game::Game(std::string filename){
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
    std::string legal_menu;
    const char* menu_options[6]={"Mark","Undo","Redo","Save","Restore","Quit"};
    char cstring[] {"MURSQ"};
    menu_c("Menu", 6, menu_options, cstring);
    }


