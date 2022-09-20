
#ifndef GAME_HPP
#define GAME_HPP

#include "tools.hpp"

class Board;

class Game{
    private:
        inline static const char* menu[6] = {"Mark", "Undo", "Redo", "Save", "Restore", "Quit"};
        Board* puzzle;
        int n = 9;
        char gameType = 't';
        ifstream file;

    public:
        Game(string);
        void run();
};

#endif