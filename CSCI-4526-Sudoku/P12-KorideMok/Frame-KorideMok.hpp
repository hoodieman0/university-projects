// Written by James Mok

#ifndef FRAME_HPP
#define FRAME_HPP

#include "tools.hpp"
#include "State-KorideMok.hpp"

class Frame{
    private:
        State arr[81];

    public:
        Frame()=default;
        explicit Frame(State input[81]);

        Frame& operator=(const Frame&)=default; //copy assignments 
        Frame(const Frame&) = default; 
        Frame& operator=(const Frame&&)=delete; //remove move assignments. 
        Frame(const Frame&&) = delete; 
        
        ~Frame()=default;

        State& getState(int index) { return arr[index]; }
        void serialize(ofstream& outFile, const char gameType, const short n); 
        void realize(ifstream& inFile, const short n); 
        State& operator[](int index); 
};

inline State& Frame::operator[](int index) { return getState(index); }


#endif