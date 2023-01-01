// Written by James Mok

#ifndef STACK_HPP
#define STACK_HPP

#include "tools.hpp"
#include "Frame-KorideMok.hpp"

class Stack : private vector<shared_ptr<Frame>>{
    public:
        Stack()=default;
        ~Stack()=default;
        void pop() { vector::pop_back(); }
        shared_ptr<Frame> top() { return vector::back(); }
        void push(shared_ptr<Frame> frame) { vector::push_back(frame); }
        int size() { return vector::size(); }
        void zap() { while (!vector::empty()) vector::pop_back(); }

};

#endif