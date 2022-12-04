// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef STATE_H
#define STATE_H

#include "tools.hpp"
#include "Exceptions-KorideMok.hpp"

class State {
protected:
    short posList = 0x3FE; //0011 1111 1110
    char value = '-';
    bool fixed = false; //is part of the original puzzle

public:
    State(char='-');
    ~State() = default;
    virtual void mark(char);
    char getValue() const { return value; }
    bool getFixed() const { return fixed; }
    string getPosList() const;

    //I hate setters, but in order to use Undo/Redo it is necessary for
    //State to be a variable in Square
    void setValue(char val) { value = val; }
    void setPosList(short n) { posList = n; }
    void xorBit(short n) { posList = posList ^ n; }

    ostream& print(ostream&) const;
};

inline ostream& operator <<(ostream& out, State& st){
    return st.print(out);
}

#endif