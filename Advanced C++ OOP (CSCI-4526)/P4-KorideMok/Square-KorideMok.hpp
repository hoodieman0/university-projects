// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef SQUARE_H
#define SQUARE_H

#include "tools.hpp"
#include "State-KorideMok.hpp"

class Square{
    private:
        State info;
        short row = 0;
        short col = 0;
        vector<Square*> buddies;

    public:
        Square() { }//cout <<"Square Default Constructor" << endl; }
        Square(char, short, short);
        ~Square() { }//cout <<"Destroying Square " <<row <<", " <<col <<endl; }
        void mark(char);
        ostream& print(ostream&); //follows matrix convention [rows, columns]
};

inline ostream& operator <<( ostream& out, Square& sq){
    return sq.print(out);
}

#endif