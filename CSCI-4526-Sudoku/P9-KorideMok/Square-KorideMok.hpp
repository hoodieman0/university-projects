// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef SQUARE_H
#define SQUARE_H

#include "tools.hpp"
#include "State-KorideMok.hpp"

class Cluster;

class Square : public State{
    private:
        short row = 0;
        short col = 0;
        vector<Cluster*> buddies;

    public:
        Square() = default;
        Square(char, short, short);
        ~Square() = default;
        void mark(char);
        void addCluster(Cluster* cl) { buddies.push_back(cl); }
        void shoop(char);
        void turnOff(int);
        void setState(State newState);
        ostream& print(ostream&) const; //follows matrix convention [rows, columns]
};

inline ostream& operator <<( ostream& out, Square& sq){
    return sq.print(out);
}

#endif