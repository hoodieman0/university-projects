// Written by James Mok and Niel Koride

#ifndef CSCI_4526_SUDOKU_PROJECT_MASTER_STATE_KORIDEMOK_HPP
#define CSCI_4526_SUDOKU_PROJECT_MASTER_STATE_KORIDEMOK_HPP

#include "tools.hpp"

class State {
private:
    short possibilities = 0x3FE;
    char value;
    bool fixed; //is part of the original puzzle

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


#endif //CSCI_4526_SUDOKU_PROJECT_MASTER_STATE_KORIDEMOK_HPP
