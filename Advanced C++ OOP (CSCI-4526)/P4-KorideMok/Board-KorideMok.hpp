// Written by James Mok and Neelakanta Bharadwaj Koride

#include "tools.hpp"
#include "Square-KorideMok.hpp"
#pragma once

class Board{
    private:
        short n; // Size of the puzzle
        Square* bd;
        ifstream& file;
        short left;
        void getPuzzle();

    public:
        Board(short, ifstream&);
        ~Board(){ cout <<"~Destroying Board~" <<endl; delete[] bd; }
        Square& sub(int j, int k){ return bd[(j - 1)* n + (k - 1)]; }
        void mark(int r, int c, char value) { sub(r, c).mark(value); }
        ostream& print(ostream&);
};

inline ostream& operator<<(ostream& out,Board& b){
    return b.print(out);
}