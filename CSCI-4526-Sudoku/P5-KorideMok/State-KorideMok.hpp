// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef STATE_H
#define STATE_H

#include "tools.hpp"

class State {
private:
    short poslist = 0x3FE; //0011 1111 1110
    char value = '-';
    bool fixed = false; //is part of the original puzzle

public:
    State() = default;
    State(char);
    ~State() = default;
    void markState(char);
    char getValue() const { return value; }
    void turnOffBit(short);
    ostream& printState(ostream&);
};

inline ostream& operator <<(ostream& out, State& st){
    return st.printState(out);
}

#endif