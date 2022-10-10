// Written by James Mok and Neelakanta Bharadwaj Koride

#include "Cluster-KorideMok.hpp"


Cluster::Cluster(ClusterType type, Square* arr[9]) : type(type){
    for (int index = 0; index < 9; index++){
        clstr[index] = arr[index];
        clstr[index]->addCluster(this);
    }
}


void Cluster::
shoop(char val){
    int n = val - '0';
    for (Square* square : clstr) { square->turnOff(n); }
}

ostream& Cluster::print(ostream& out) {
    out << type <<endl;
    for (Square* square : clstr) { out <<square <<endl; }
    out <<endl;

}
