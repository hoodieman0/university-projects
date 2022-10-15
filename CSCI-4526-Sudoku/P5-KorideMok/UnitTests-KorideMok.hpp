// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef UNITTESTS_H
#define UNITTESTS_H

#include "tools.hpp"
#include "State-KorideMok.hpp" //P1
#include "Square-KorideMok.hpp" //P2
#include "Game-KorideMok.hpp" //P3
#include "Board-KorideMok.hpp" //P4

void testStateFunctions(ostream&); //P1
void testSquareFunctions(ostream&); //P2
void testBoardFunctions(ostream&, char*); //P4
void testClusterFunctions(ostream&, char*); //P5

inline void testP1(ostream& out) { testSquareFunctions(out); }
inline void testP2(ostream& out) {
    testSquareFunctions(out);
    out <<"-----------------------------------------------------"
          "-----------------------------------------------------" <<endl;
    testStateFunctions(out);
}

inline void testP3(ostream& out) { }
inline void testP4(ostream& out) { }
inline void testP5(ostream& out, char* filename) {
    out <<"~Begin Cluster Test~\n---------------------------------------------------" <<endl;
    testClusterFunctions(out, filename);
    out <<"\n~Cluster Test Completed Successfully~\n-----------------------------------------"
      "----------" <<endl;
}

#endif
