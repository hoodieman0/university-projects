// Written by James Mok

#include "Frame-KorideMok.hpp"

// ---------------------------------------------------------------------
// Frame constructor
// Precondition: State object array exists
// Postcondition: The States in the array are put into the Frame's array
Frame::
Frame(State input[81]){
    for (int i = 0; i < 81; i++){
        arr[i] = input[i];
    }
}

// ---------------------------------------------------------------------
// Saves the game to the ostream
// Precondition: Frame object, ostream exists
// Postcondition: outFile has States printed to it
void Frame::
serialize(ofstream& outFile){
    for (int i = 0; i < 81; i++){
        outFile <<arr[i].getValue();
    }
}

// ---------------------------------------------------------------------
// Reloads the game with new States from the ifstream
// Precondition: Game object, undo Stack exists
// Postcondition: The Frame arr[] is filled with the values in the ifstream
void Frame::
realize(ifstream& inFile){
    char x;
    for (int i = 0; i < 81; i++){
        inFile>> x;
        State temp(x);
        arr[i] = temp;
    }
}