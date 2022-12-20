// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef GAME_HPP
#define GAME_HPP

#include "tools.hpp"
#include "Board-KorideMok.hpp"
#include "BoardTypes-KorideMok.hpp"
#include "Stack-KorideMok.hpp"
#include "Frame-KorideMok.hpp"
#include "Viewer.hpp"

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
        void Save();
        void Restore();


    public:
        Game(ifstream& input);
        void run();
};

#endif