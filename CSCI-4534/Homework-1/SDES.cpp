#include "SDES.hpp"

SDES::
SDES(const unsigned int key, bool output, bool verbose) : output(output), verbose(verbose) {
    keyGen(key);
}

void SDES::
keyGen(const unsigned int key){
    // P10 -> SHIFT -> P8 -> keyOne
    // P10 -> SHIFT -> SHIFT-> P8 -> keyTwo
    unsigned int resultP10 = permute10(key);

    unsigned int left10 = resultP10 & LeftBits;
    left10 = left10 >> 5;
    left10 = leftShift(left10);

    unsigned int right10 = leftShift(resultP10 & RightBits);
    unsigned int combined = (left10 << 5) + right10;
    keyOne = permute8(combined);

    left10 = leftShift(left10);
    right10 = leftShift(right10);
    combined = (left10 << 5) + right10;

    keyTwo = permute8(combined);
}