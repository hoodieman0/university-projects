// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef STATE_KORIDEMOK_H
#define STATE_KORIDEMOK_H

#include "tools.hpp"

class State {
private:
    short poslist = 0x3FE;
    char value;
    bool fixed = false; //is part of the original puzzle

public:
    State() { cout <<"Default State Constructor" << endl; }
    State(char);
    ~State() { cout <<"Default State Destructor" <<endl; }
    void mark(char);
    char getValue() {return value;}
    void const print( ostream& out );
};

inline ostream& operator <<(ostream& out, State& state) {
    state.print(out);
    return out;
}


#endif STATE_KORIDEMOK_H
