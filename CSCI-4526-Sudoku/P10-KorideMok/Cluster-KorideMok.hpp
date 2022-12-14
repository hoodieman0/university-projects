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
        Cluster(string, Square* []);
        void shoop(char);
        const bool isValid(char) const;
        ostream& print(ostream&) const;
};

inline ostream& operator <<( ostream& out, Cluster& cl){
    return cl.print(out);
}

#endif
