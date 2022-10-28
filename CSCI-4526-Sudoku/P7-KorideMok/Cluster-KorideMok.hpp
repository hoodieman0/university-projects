// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef CLUSTER_H
#define CLUSTER_H

#include "tools.hpp"
#include "Square-KorideMok.hpp"

class Cluster{
    private:
        const string type;
        Square* clstr[9];

    public:
        Cluster(const string, Square* []);
        void shoop(char);
        bool isValid(char);
        ostream& print(ostream&);
};

inline ostream& operator <<( ostream& out, Cluster& cl){
    return cl.print(out);
}

#endif
