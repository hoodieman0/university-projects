// Written by James Mok and Niel Koride

#ifndef P1_MOK_SQUARE_KORIDEMOK_H
#define P1_MOK_SQUARE_KORIDEMOK_H

#include "tools.hpp"
#include "State-KorideMok.hpp"

ostream& print( ostream& );

class Square{
    private:
        State info;
        short row;
        short col;
        vector<Square> buddies;

    public:
        Square() { cout <<"Square Default Constructor" << endl; }
        Square(char, short, short);
        ~Square() { cout <<"Destroying Square " <<row <<", " <<col <<endl; }
        void mark(char marker) { info.mark(marker); }
        ostream& print(ostream&); //follows matrix convention [rows, columns]
};

inline ostream& operator <<( ostream& out, Square& sq){
    return sq.print(out);
}

#endif P1_MOK_SQUARE_KORIDEMOK_H