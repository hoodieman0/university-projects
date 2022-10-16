// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef GAME_HPP
#define GAME_HPP

#include "tools.hpp"
#include "Board-KorideMok.hpp"

class Game{
    private:
        const static string menu[6];
        Board* puzzle;
        int n = 9;
        char gameType = 't';
        ifstream file;

    public:
        Game(char*);
        ~Game() { delete puzzle; }
        void run();
};

#endif