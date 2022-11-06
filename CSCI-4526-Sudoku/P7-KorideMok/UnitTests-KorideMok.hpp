// Written by James Mok and Neelakanta Bharadwaj Koride

#ifndef UNITTESTS_H
#define UNITTESTS_H

#include "tools.hpp"
#include "State-KorideMok.hpp" //P1
#include "Square-KorideMok.hpp" //P2
#include "Game-KorideMok.hpp" //P3
#include "Board-KorideMok.hpp" //P4
#include "DiagBoard-KorideMok.hpp" //P6

void testStateFunctions(ostream&); //P1
void testSquareFunctions(ostream&); //P2
void testBoardFunctions(ostream&, char*); //P4
void testClusterFunctions(ostream&, char*); //P5
void testDiagonalFunctions(ostream&, char*); //P6

inline void
testP1(ostream& out) {
    out <<"~Begin State Test~\n---------------------------------------------------" <<endl;
    testSquareFunctions(out);
    out <<"\n~State Test Completed Successfully~\n-----------------------------------------"
          "----------" <<endl;
}

inline void
testP2(ostream& out) {
    out <<"~Begin Square Test~\n---------------------------------------------------" <<endl;
    testSquareFunctions(out);
    out <<"\n~Square Test Completed Successfully~\n-----------------------------------------"
          "----------" <<endl;

    out <<"~Begin State Test~\n---------------------------------------------------" <<endl;
    testStateFunctions(out);
    out <<"\n~State Test Completed Successfully~\n-----------------------------------------"
          "----------" <<endl;
}

inline void
testP3(ostream& out, const char* filename) {
    out <<"~Begin Game Test~\n---------------------------------------------------" <<endl;
    ifstream ifs(filename);
    Game obj(ifs);
    obj.run();
    out <<"\n~Game Test Completed Successfully~\n-----------------------------------------"
          "----------" <<endl;
}

inline void
testP4(ostream& out, char* filename) {
    out <<"~Begin Board Test~\n---------------------------------------------------" <<endl;
    testBoardFunctions(out, filename);
    out <<"\n~Board Test Completed Successfully~\n-----------------------------------------"
          "----------" <<endl;
}

inline void
testP5(ostream& out, char* filename) {
    out <<"~Begin Cluster Test~\n---------------------------------------------------" <<endl;
    testClusterFunctions(out, filename);
    out <<"\n~Cluster Test Completed Successfully~\n-----------------------------------------"
      "----------" <<endl;
}

inline void
testP6(ostream& out, char* filename){
    testP5(out, filename);

    out <<"~Begin Diagonal Test~\n---------------------------------------------------" <<endl;
    testDiagonalFunctions(out, filename);
    out <<"\n~Diagonal Test Completed Successfully~\n-----------------------------------------"
          "----------" <<endl;
}

#endif
