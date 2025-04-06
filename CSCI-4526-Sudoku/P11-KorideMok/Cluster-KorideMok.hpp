// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef CLUSTER_H
#define CLUSTER_H

#include "tools.hpp"
#include "Square-KorideMok.hpp"

class Cluster{
    private:
        const string type;
        Square* clstr[9] = {0};

    public:
        Cluster(string type, Square* arr[], const short amnt);
        void shoop(char);
        ostream& print(ostream&) const;
};

inline ostream& operator <<( ostream& out, Cluster& cl){
    return cl.print(out);
}

#endif
