// Written by James Mok and Niel Koride

#ifndef P1_MOK_SQUARE_KORIDEMOK_H
#define P1_MOK_SQUARE_KORIDEMOK_H

#include "tools.hpp"

class State {
    private:
        short possibilities;
        char value;
        bool fixed; //is part of the original puzzle

    public:
        State();
        State(char);
        ~State();
        void mark(char);
        char getValue() {return value;}
        void const print();
};

class Square{
    private:
        State info;
        short row;
        short col;
        vector<Square> buddies;

    public:
        Square();
        Square(char, short, short);
        ~Square();
        void mark(char);
        void getValue(); // for future use
        void const print();

};

ostream& operator <<( ostream&, Square&);

#endif P1_MOK_SQUARE_KORIDEMOK_H