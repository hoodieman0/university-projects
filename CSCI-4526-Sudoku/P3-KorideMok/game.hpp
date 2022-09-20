
#ifndef GAME_HPP
#define GAME_HPP

#include "tools.hpp"

#define MENU_ONE "Mark"
#define MENU_TWO "Undo"
#define MENU_THREE "Redo"
#define MENU_FOUR "Save"
#define MENU_FIVE "Restore"
#define MENU_SIX "Quit"

class Board;

class Game{
    private:
        const char* menu[6] ={MENU_ONE, MENU_TWO, MENU_THREE, MENU_FOUR, MENU_FIVE, MENU_SIX};
        Board* puzzle;
        int n = 9;
        char gameType = 't';
        ifstream file;
    public:
        Game(string);
        void run();
};

#endif