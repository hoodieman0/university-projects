// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef CLUSTER_H
#define CLUSTER_H

#include "tools.hpp"
#include "Square-KorideMok.hpp"
#include "Board-KorideMok.hpp" //TODO REMOVE

class Cluster{
    private:
        ClusterType type; //TODO CHANGE
        Square* clstr[9];

    public:
        Cluster(ClusterType, Square**);
        void shoop(char);
        ostream& print(ostream&);
};

inline ostream& operator <<( ostream& out, Cluster& cl){
    return cl.print(out);
}

#endif
