// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef SQUARE_H
#define SQUARE_H

#include "tools.hpp"
#include "State-KorideMok.hpp"
#include "Exceptions.hpp"

class Cluster;

class Square : private State{ //TODO see if can be protected
    private:
        short row = 0;
        short col = 0;
        vector<Cluster*> buddies;

    public:
        Square() = default;
        Square(char, short, short);
        ~Square() = default;
        void mark(char);
        char getState() const { return getValue(); }
        void addCluster(Cluster* cl) { buddies.push_back(cl); }
        void shoop(char);
        void turnOff(int);
        ostream& print(ostream&); //follows matrix convention [rows, columns]
};

inline ostream& operator <<( ostream& out, Square& sq){
    return sq.print(out);
}

#endif