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

// meant for 10 bit numbers only
// returns a 10 bit number
unsigned int SDES::
permute10(unsigned int bits){
    // The 10 bit representation:
    // k1 k2 k3 k4 k5 k6 k7 k8 k9 k10
    // becomes 
    // k3 k5 k2 k7 k4 k10 k1 k9 k8 k6

    unsigned int 
    k1 =  0b1000000000,
    k2 =  0b0100000000,
    k3 =  0b0010000000,
    k4 =  0b0001000000,
    k5 =  0b0000100000,
    k6 =  0b0000010000,
    k7 =  0b0000001000,
    k8 =  0b0000000100,
    k9 =  0b0000000010,
    k10 = 0b0000000001;

    unsigned int permutation = 
    ((bits & k3) << 2) +
    ((bits & k5) << 3) +
    ((bits & k2) >> 1) +
    ((bits & k7) << 3) +
    ((bits & k4) >> 1) +
    ((bits & k10) << 4) +
    ((bits & k1) >> 6) +
    ((bits & k9) << 1) +
    ((bits & k8) >> 1) +
    ((bits & k6) >> 4);

    if (verbose) 
        cout << "The permute10 result of " << bitset<10>(bits) << " is: " 
        << right << setw(19) << bitset<10>(permutation) << endl;

    return permutation;
}

// meant for 10 bit numbers only
// returns a 8 bit number
unsigned int SDES::
permute8(unsigned int bits){
    // The 10 bit representation:
    // k1 k2 k3 k4 k5 k6 k7 k8 k9 k10
    // becomes 
    // 0  0  k6 k3 k7 k4 k8 k5 k10 k9

    unsigned int 
    k3 =  0b0010000000,
    k4 =  0b0001000000,
    k5 =  0b0000100000,
    k6 =  0b0000010000,
    k7 =  0b0000001000,
    k8 =  0b0000000100,
    k9 =  0b0000000010,
    k10 = 0b0000000001;

    // shifts are done to make k9 the least significant bit
    // everything was shifted to the right by 2
    unsigned int permutation = 
    ((bits & k6) << 3) +
    ((bits & k3) >> 1) +
    ((bits & k7) << 2) +
    ((bits & k4) >> 2) +
    ((bits & k8) << 1) +
    ((bits & k5) >> 3) +
    ((bits & k10) << 1) +
    ((bits & k9) >> 1);

    if (verbose) 
        cout << "The permute8 result of " << bitset<10>(bits) << " is: "
        << right << setw(20) << bitset<8>(permutation) << endl;


    return permutation;
}

// meant for 5 bit numbers only
// returns a 5 bit number
unsigned int SDES::
leftShift(unsigned int bits){
    // The 5 bit representation:
    // k1 k2 k3 k4 k5
    // becomes 
    // k2 k3 k4 k5 k1

    unsigned int k1 = 0b10000;

    unsigned int shift = 
    ((bits & k1) >> 4) + (bits << 1);

    if (verbose)
        cout << "The result of left shifting " << bitset<5>(bits) << 
        " is: " << right << setw(20) << bitset<5>(shift) << endl;


    return shift & RightBits; // remove extra leading 1s
}
