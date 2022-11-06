// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef GAME_HPP
#define GAME_HPP

#include "Board-KorideMok.hpp"
#include "tools.hpp"

class Game{
    private:
        const string menu[6] = {"Mark", "Undo", "Redo", "Save", "Restore", "Quit"};
        Board* puzzle;
        short n;
        char gameType;
        ifstream& file;

    public:
        Game(ifstream&);
        ~Game() { delete puzzle; }
        void run();
};

#endif