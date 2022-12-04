// Written by James Mok

#include "Frame-KorideMok.hpp"

Frame::Frame(State* input){
    for (int i = 0; i < 81; i++){
        arr[i] = input[i];
    }
}