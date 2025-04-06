// Written by James Mok and Niel Koride

#ifndef State_H
#define State_H

#include "tools.hpp"

class State {
    private:
        short poslist = 0x3FE; //binary: 0011 1111 1110
        char value = '-';
        bool fixed = false; //is part of the original puzzle

    public:
        inline State() { cout << "Default State Constructor" << endl; }
        State(char);
        inline ~State() { cout << "Default State Destructor" << endl; }
        void mark(char);
        ostream& print(ostream&);
};

inline ostream& operator <<(ostream& out, State& st){
    return st.print(out);
}

#endif