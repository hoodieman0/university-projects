#include "SDES.hpp"

SDES::
SDES(const unsigned int key, bool output, bool verbose) : output(output), verbose(verbose) {
    keyGen(key);
}

void SDES::
keyGen(const unsigned int key){
    // P10 -> SHIFT -> P8 -> keyOne
    // P10 -> SHIFT -> SHIFT-> P8 -> keyTwo

    if (verbose)
        cout << "----------------------------------------------------------\n" << 
        "keyGen():" << endl;
    unsigned int resultP10 = permute10(key);

    unsigned int leftBits = resultP10 & hx2E0;
    leftBits = leftBits >> 5;
    leftBits = leftShift(leftBits);

    unsigned int rightBits = leftShift(resultP10 & hx01F);
    unsigned int combined = (leftBits << 5) + rightBits;
    keyOne = permute8(combined);

    leftBits = leftShift(leftShift(leftBits));
    rightBits = leftShift(leftShift(rightBits));
    combined = (leftBits << 5) + rightBits;

    keyTwo = permute8(combined);

    if (verbose){
        cout << "----------------------------------------------------------" << endl;
        cout << "The value of KeyOne is: " << 
            right << setw(34) << bitset<8>(keyOne) << endl;
        cout << "The value of KeyTwo is: " << 
            right << setw(34) << bitset<8>(keyTwo) << endl;
    }
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


    return shift & hx01F; // remove extra leading 1s
}

// meant for 8 bit numbers
// returns an 8 bit number
unsigned int SDES::
encrypt(const unsigned int plaintext){
    // IP -> smallF w/ K1 -> SW -> smallF w/ K2 -> inverseIP 

    if (verbose)
        cout << "----------------------------------------------------------\n" << 
        "encrypt():" << endl;

    unsigned int result = initPermute(plaintext);
    unsigned int leftBits = (result & hxF0) >> 4; // keep start at least significant bit
    unsigned int rightBits = result & hx0F;

    result = processKeyAndText(keyOne, rightBits);
    leftBits = leftBits ^ result;

    // swap here
    result = (rightBits << 4) + leftBits;

    if (verbose)
        cout << "Swapping left and right bits..." << endl;
    if (output || verbose)
        cout << "The intermediate value after the SW operation is: " <<
        right << setw(0) << bitset<8>(result) << endl;

    result = processKeyAndText(keyTwo, leftBits);
    rightBits = rightBits ^ result;

    unsigned int combined = (rightBits << 4) + leftBits;
    unsigned int ciphertext = inverseInitPermute(combined);

     if (verbose)
        cout << "----------------------------------------------------------\n" << 
            "The value of the ciphertext is: " << 
            right << setw(26) << bitset<8>(ciphertext) << endl;

    return ciphertext;
}

// meant for 8 bit numbers
// returns an 8 bit number
unsigned int SDES::
decrypt(const unsigned int ciphertext){
    // IP -> smallF w/ K2 -> SW -> smallF w/ K1 -> inverseIP 

    if (verbose)
        cout << "----------------------------------------------------------\n" << 
        "decrypt():" << endl;

    unsigned int result = initPermute(ciphertext);
    unsigned int leftBits = (result & hxF0) >> 4; // keep start at least significant bit
    unsigned int rightBits = result & hx0F;

    result = processKeyAndText(keyTwo, rightBits);
    leftBits = leftBits ^ result;

    // swap here
    result = (rightBits << 4) + leftBits;

    if (verbose)
        cout << "Swapping left and right bits..." << endl;
    if (output || verbose)
        cout << "The intermediate value after the SW operation is: " <<
        right << setw(0) << bitset<8>(result) << endl;

    result = processKeyAndText(keyOne, leftBits);
    rightBits = rightBits ^ result;

    unsigned int combined = (rightBits << 4) + leftBits;
    unsigned int plaintext = inverseInitPermute(combined);

     if (verbose)
        cout << "----------------------------------------------------------\n" << 
            "The value of the plaintext is: " << 
            right << setw(27) << bitset<8>(plaintext) << endl;

    return plaintext;
}

// meant for 8 bit numbers
// returns an 8 bit number
unsigned int SDES::
initPermute(unsigned int text) {
    // The 8 bit representation:
    // k1 k2 k3 k4 k5 k6 k7 k8
    // becomes 
    // k2 k6 k3 k1 k4 k8 k5 k7
    
    unsigned int
    k1 =  0b10000000,
    k2 =  0b01000000,
    k3 =  0b00100000,
    k4 =  0b00010000,
    k5 =  0b00001000,
    k6 =  0b00000100,
    k7 =  0b00000010,
    k8 =  0b00000001;

    unsigned int permutation = 
    ((text & k2) << 1) +
    ((text & k6) << 4) +
    ((text & k3) << 0) +
    ((text & k1) >> 3 ) +
    ((text & k4) >> 1) +
    ((text & k8) << 2) +
    ((text & k5) >> 2) +
    ((text & k7) >> 1);

    if (verbose) 
        cout << "The initPermute result of " << bitset<8>(text) << " is: "
        << right << setw(19) << bitset<8>(permutation) << endl;

    return permutation;
}

// meant for 4 bit numbers
// returns a 4 bit number
unsigned int SDES::
processKeyAndText(unsigned int key, unsigned int text){
    unsigned int result = expandPermute4(text);
    result = result ^ key;

    if (verbose)
        cout << "The XOR of expandPermute4 and key is: " << right << setw(20) << bitset<8>(result) << endl;

    unsigned int leftBits = (hxF0 & result) >> 4; // shift to start at least significant bit
    unsigned int rightBits = hx0F & result;

    if (verbose) {
        cout << "Indexing S0" << "[" << (leftBits & hx1) + ((leftBits & hx9) >> 2) << "]" << "[" << ((leftBits & hx6) >> 1) << "]" <<
        " and S1" << "[" << (rightBits & hx1) + (rightBits >> 2) << "]" << "[" << ((rightBits & hx6) >> 1) << "]" << "..."<< endl;
    }

    unsigned int combined = 
    (S0[(leftBits & hx1) + ((leftBits & hx9) >> 2)][(leftBits & hx6) >> 1] << 2) +
    S1[(rightBits & hx1) + (rightBits >> 2)][(rightBits & hx6) >> 1];

    if (verbose)
        cout << "The combination of S0 and S1 is: " << right << setw(25) << bitset<4>(combined) << endl;

    result = permute4(combined);

    if (verbose)
        cout << "The processing of key " << bitset<8>(key) << " and text "<< bitset<4>(text) <<
        " is: " << right << setw(9) << bitset<4>(result) << endl;

    return result;
}

// meant for 4 bit number
// returns an 8 bit number
unsigned int SDES::expandPermute4(unsigned int bits){
    // The 4 bit representation:
    // 0  0  0  0  k1 k2 k3 k4
    // becomes 
    // k4 k1 k2 k3 k2 k3 k4 k1 

    unsigned int 
    k1 =  0b1000,
    k2 =  0b0100,
    k3 =  0b0010,
    k4 =  0b0001;

    unsigned int permutation = 
    ((bits & k4) << 7) +
    ((bits & k1) << 3) +
    ((bits & k2) << 3) +
    ((bits & k3) << 3) +
    ((bits & k2) << 1) +
    ((bits & k3) << 1) +
    ((bits & k4) << 1) +
    ((bits & k1) >> 3);

    if (verbose) 
        cout << "The expandPermute4 result of " << bitset<4>(bits) << " is: "
        << right << setw(20) << bitset<8>(permutation) << endl;

    return permutation;
}

// meant for 4 bit number
// returns a 4 bit number
unsigned int SDES::permute4(unsigned int bits){
    // The 4 bit representation:
    // k1 k2 k3 k4
    // becomes 
    // k2 k4 k3 k1

    unsigned int 
    k1 =  0b1000,
    k2 =  0b0100,
    k3 =  0b0010,
    k4 =  0b0001;

    unsigned int permutation = 
    ((bits & k2) << 1) +
    ((bits & k4) << 2) +
    ((bits & k3) << 0) +
    ((bits & k1) >> 3);

    if (verbose) 
        cout << "The permute4 result of " << bitset<4>(bits) << " is: "
        << right << setw(26) << bitset<4>(permutation) << endl;

    return permutation;
}


// meant for 8 bit numbers
// returns an 8 bit number
unsigned int SDES::
inverseInitPermute(unsigned int text){
    // The 8 bit representation:
    // k1 k2 k3 k4 k5 k6 k7 k8
    // becomes 
    // k4 k1 k3 k5 k7 k2 k8 k6
    
    unsigned int
    k1 =  0b10000000,
    k2 =  0b01000000,
    k3 =  0b00100000,
    k4 =  0b00010000,
    k5 =  0b00001000,
    k6 =  0b00000100,
    k7 =  0b00000010,
    k8 =  0b00000001;

    unsigned int permutation = 
    ((text & k4) << 3) +
    ((text & k1) >> 1) +
    ((text & k3) << 0) +
    ((text & k5) << 1 ) +
    ((text & k7) << 2) +
    ((text & k2) >> 4) +
    ((text & k8) << 1) +
    ((text & k6) >> 2);

    if (verbose) 
        cout << "The inverseInitPermute result of " << bitset<8>(text) << " is: "
        << right << setw(12) << bitset<8>(permutation) << endl;

    return permutation;
}