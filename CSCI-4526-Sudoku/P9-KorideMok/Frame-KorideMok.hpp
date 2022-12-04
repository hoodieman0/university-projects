// Written by James Mok

#ifndef FRAME_HPP
#define FRAME_HPP

#include "tools.hpp"
#include "State-KorideMok.hpp"

class Frame{
    private:
        State arr[81];

    public:
        Frame()=delete;
        Frame(State*);
        ~Frame()=default;
        State getState(int index) { return arr[index]; }
};

#endif