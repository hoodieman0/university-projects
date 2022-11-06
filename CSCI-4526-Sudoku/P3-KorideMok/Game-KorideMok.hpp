// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef GAME_HPP
#define GAME_HPP

#include "tools.hpp"

class Board;

class Game{
    private:
        const string menu[6] = {"Mark", "Undo", "Redo", "Save", "Restore", "Quit"};;
        Board* puzzle;
        int n = 9;
        char gameType = 't';
        ifstream& file;

    public:
        Game(ifstream&);
        ~Game() { delete puzzle; }
        void run();
};

#endif