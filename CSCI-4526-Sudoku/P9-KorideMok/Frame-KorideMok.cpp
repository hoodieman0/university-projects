// Written by James Mok

#include "Frame-KorideMok.hpp"

// --------------------------------------------------------------------- 
// Frame constructor 
// Precondition: State object array exists 
// Postcondition: The States in the array are put into the Frame's array 
Frame::
Frame(State* input){
    for (int i = 0; i < 81; i++){
        arr[i] = input[i];
    }
}