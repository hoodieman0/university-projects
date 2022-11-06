// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef GAME_HPP
#define GAME_HPP

#include "tools.hpp"
#include "Board-KorideMok.hpp"
#include "DiagBoard-KorideMok.hpp"

class Game{
    private:
        const string menu[7] {"Print", "Mark", "Undo", "Redo", "Save", "Restore", "Quit"};
        Board* puzzle;
        short n;
        char gameType;
        ifstream& file;

    public:
        Game(ifstream&);
        void run();
};

#endif