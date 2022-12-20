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
    ~State()=default;
    virtual void mark(char val);
    short getPosList() const { return posList; }
    char getValue() const { return value; }
    bool getFixed() const { return fixed; }
    string getPosListString() const;
    ostream& print(ostream& out) const;
};

inline ostream& operator <<(ostream& out, State& st){
    return st.print(out);
}

#endif