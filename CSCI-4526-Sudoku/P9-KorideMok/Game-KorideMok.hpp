// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef GAME_HPP
#define GAME_HPP

#include "tools.hpp"
#include "Board-KorideMok.hpp"
#include "DiagBoard-KorideMok.hpp"
#include "Stack-KorideMok.hpp"
#include "Viewer.hpp"
#include "Stack-KorideMok.hpp"

class Game{
    private:
        static const string menu[7];
        Board* puzzle;
        short n;
        char gameType;
        ifstream& file;

        Stack undo, redo;

        void Mark();
        void TurnOff();
        void NewMove();
        void Undo();
        void Redo();


    public:
        Game(ifstream&);
        void run();
};

#endif