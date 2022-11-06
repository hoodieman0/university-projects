// Written by James Mok and Neelakanta Bharadwaj Koride

#include "tools.hpp"
#include "Square-KorideMok.hpp"
#include "Cluster-KorideMok.hpp"
#pragma once

enum class ClusterType {ROW=0, COLUMN, BOX, DIAGONAL};

class Board{
    protected:
        short n; // Size of the puzzle
        Square* bd;
        ifstream& file;
        short left;
        vector<Cluster*> buddies;

        void getPuzzle();
        void makeClusters();
        void createRow(short);
        void createCol(short);
        void createBox(short, short);

    public:
        Board(short, short, ifstream&);
        ~Board(){ cout <<"~Destroying Board~" <<endl; delete[] bd; }
        Square& sub(const short r, const short c) const { return bd[(r - 1)* n + (c - 1)]; }
        void mark(const short, const short, const char) const;
        ostream& print(ostream&) const ;
};

inline ostream& operator<<(ostream& out, Board& b){
    return b.print(out);
}