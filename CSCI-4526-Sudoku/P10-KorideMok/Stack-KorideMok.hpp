// Written by James Mok

#ifndef STACK_HPP
#define STACK_HPP

#include "tools.hpp"
#include "Frame-KorideMok.hpp"

class Stack : private vector<Frame*>{
    public:
        Stack()=default;
        ~Stack()=default;
        void pop() { vector::pop_back(); }
        Frame* top() { return vector::back(); }
        void push(Frame* frame) { vector::push_back(frame); }
        int size() { return vector::size(); }
        void zap() { while (!vector::empty()) vector::pop_back(); }

};

#endif