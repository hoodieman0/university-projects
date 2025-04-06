#include "SDES.hpp"

/// ----------------------------------------------------------------------------
/// @brief SDES class constructor
/// @param key (unsigned int) a 10-bit number that serves as the encryption key
/// @param output (bool) flag to send homework outputs to console
/// @param verbose (bool) flag to send debugging outputs to console
/// ----------------------------------------------------------------------------
SDES::
SDES(const unsigned int key, bool output, bool verbose) : output(output), verbose(verbose) {
    keyGen(key); // on class creation, create the keys
}

/// ----------------------------------------------------------------------------
/// @brief Generates keyOne and keyTwo according to SDES standard
/// @param key (unsigned int) a 10-bit key that derives keyOne and keyTwo
/// ----------------------------------------------------------------------------
void SDES::
keyGen(const unsigned int key){
    // P10 -> SHIFT -> P8 -> keyOne
    // P10 -> SHIFT -> SHIFT-> P8 -> keyTwo

    if (verbose)
        cout << "----------------------------------------------------------\n" << 
        "keyGen():" << endl;

    // permute10 the given key
    unsigned int resultP10 = permute10(key);

    // grab the left most bits
    unsigned int leftBits = resultP10 & hx2E0;
    leftBits = leftBits >> 5;                   // make bits be in least significant bit slot
    leftBits = leftShift(leftBits);             // left shift the left bits

    // grab the right bits and left shift them
    unsigned int rightBits = leftShift(resultP10 & hx01F);

    // recombine the bits into one variable
    unsigned int combined = (leftBits << 5) + rightBits;

    // the permute8 of the previous combination is the first key
    keyOne = permute8(combined);

    // left shift both the left and right bits by two and recombine them
    leftBits = leftShift(leftShift(leftBits));
    rightBits = leftShift(leftShift(rightBits));
    combined = (leftBits << 5) + rightBits;

    // the permute8 of the latest combination is the second key
    keyTwo = permute8(combined);

    if (verbose){
        cout << "----------------------------------------------------------" << endl;
        cout << "The value of KeyOne is: " << 
            right << setw(34) << bitset<8>(keyOne) << endl;
        cout << "The value of KeyTwo is: " << 
            right << setw(34) << bitset<8>(keyTwo) << endl;
    }
}

/// ----------------------------------------------------------------------------
/// @brief a 10-bit permutation for SDES key generation
///        the first step when encoding the keys 
/// @param bits (unsigned int) a 10-bit number to permute
/// @return (unsigned int) the new 10-bit number changed according to SDES key
///         generation standards
/// ----------------------------------------------------------------------------
unsigned int SDES::
permute10(unsigned int bits){
    // The 10 bit representation:
    // k1 k2 k3 k4 k5 k6 k7 k8 k9 k10
    // becomes 
    // k3 k5 k2 k7 k4 k10 k1 k9 k8 k6

    // create bit masks
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

    // grab the respectve bits and put them into their new positions 
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

/// ----------------------------------------------------------------------------
/// @brief an 8-bit permutation for SDES key generation
///        the second permutation when encoding the keys 
/// @param bits (unsigned int) an 8-bit number to permute
/// @return (unsigned int) the new 8-bit number changed from bits 
///         according to SDES key generation standards
/// ----------------------------------------------------------------------------
unsigned int SDES::
permute8(unsigned int bits){
    // The 10 bit representation:
    // k1 k2 k3 k4 k5 k6 k7 k8 k9 k10
    // becomes 
    // 0  0  k6 k3 k7 k4 k8 k5 k10 k9

    // create bit masks
    unsigned int 
    k3 =  0b0010000000,
    k4 =  0b0001000000,
    k5 =  0b0000100000,
    k6 =  0b0000010000,
    k7 =  0b0000001000,
    k8 =  0b0000000100,
    k9 =  0b0000000010,
    k10 = 0b0000000001;

    // grab the respectve bits and put them into their new positions 
    // shifts are done to make k9 the least significant bit
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

/// ----------------------------------------------------------------------------
/// @brief a 5-bit left shift, where the left-most bit becomes the right-most bit
/// @param bits (unsigned int) a 5-bit number to shift
/// @return (unsigned int) the new 5-bit number changed from bits 
///         with its bits shifted left and wrapped once
/// ----------------------------------------------------------------------------
unsigned int SDES::
leftShift(unsigned int bits){
    // The 5 bit representation:
    // k1 k2 k3 k4 k5
    // becomes 
    // k2 k3 k4 k5 k1

    // create bit mask
    unsigned int k1 = 0b10000;

    // shift bits left once and add masked bit to the beginning
    unsigned int shift = 
    ((bits & k1) >> 4) + (bits << 1);

    if (verbose)
        cout << "The result of left shifting " << bitset<5>(bits) << 
        " is: " << right << setw(20) << bitset<5>(shift) << endl;


    return shift & hx01F; // remove extra leading 1s and return
}

/// ----------------------------------------------------------------------------
/// @brief the SDES encryption algorithm to obscure information
/// @param plaintext (unsigned int) the 8-bit number considered as the message
/// @return (unsigned int) the 8-bit number cipher text using keyOne and keyTwo
/// ----------------------------------------------------------------------------
unsigned int SDES::
encrypt(const unsigned int plaintext){
    // IP -> F w/ K1 -> SW -> F w/ K2 -> inverseIP 

    if (output || verbose)
        cout << "----------------------------------------------------------\n" << 
        "encrypt():" << endl;

    // permute the initial bits through IP and separate left and right bits
    unsigned int result = initPermute(plaintext);
    unsigned int leftBits = (result & hxF0) >> 4; // keep start at least significant bit
    unsigned int rightBits = result & hx0F;

    // grab bits to xor the left bits
    result = processKeyAndText(keyOne, rightBits);
    leftBits = leftBits ^ result;

    // swap left and right bits here
    result = (rightBits << 4) + leftBits; // this line is used for outputs

    if (verbose)
        cout << "Swapping left and right bits..." << endl;
    if (output || verbose)
        cout << "The intermediate value after the SW operation is: " <<
        right << setw(0) << bitset<8>(result) << endl;

    // grab bits to xor with right bits (after swap)
    result = processKeyAndText(keyTwo, leftBits);
    rightBits = rightBits ^ result;

    // recombine the left and right bits and run them through inverse IP to get ciphertext
    unsigned int combined = (rightBits << 4) + leftBits;
    unsigned int ciphertext = inverseInitPermute(combined);

    if (output || verbose) {
        if (verbose) cout << "----------------------------------------------------------" << endl; 
        cout << "The value of the ciphertext is: " << 
            right << setw(26) << bitset<8>(ciphertext) << endl;
     }

    return ciphertext;
}

/// ----------------------------------------------------------------------------
/// @brief the SDES decryption algorithm to read obscured information
/// @param ciphertext (unsigned int) the 8-bit number considered as the cipher text
/// @return (unsigned int) the 8-bit number plain text using keyTwo and keyOne
/// ----------------------------------------------------------------------------
unsigned int SDES::
decrypt(const unsigned int ciphertext){
    // IP -> F w/ K2 -> SW -> F w/ K1 -> inverseIP 

    if (output|| verbose)
        cout << "----------------------------------------------------------\n" << 
        "decrypt():" << endl;

    // permute the initial bits through IP and separate left and right bits
    unsigned int result = initPermute(ciphertext);
    unsigned int leftBits = (result & hxF0) >> 4; // keep start at least significant bit
    unsigned int rightBits = result & hx0F;

    // grab bits to xor the left bits
    result = processKeyAndText(keyTwo, rightBits);
    leftBits = leftBits ^ result;

    // swap left and right bits here
    result = (rightBits << 4) + leftBits; // this line is used for outputs

    if (verbose)
        cout << "Swapping left and right bits..." << endl;
    if (output || verbose)
        cout << "The intermediate value after the SW operation is: " <<
        right << setw(0) << bitset<8>(result) << endl;

    // grab bits to xor with right bits (after swap)
    result = processKeyAndText(keyOne, leftBits);
    rightBits = rightBits ^ result;

    // recombine the left and right bits and run them through inverse IP to get plaintext
    unsigned int combined = (rightBits << 4) + leftBits;
    unsigned int plaintext = inverseInitPermute(combined);

    if (output || verbose) {
        if (verbose) cout << "----------------------------------------------------------" << endl; 
        cout << "The value of the plaintext is: " << 
            right << setw(27) << bitset<8>(plaintext) << endl;
     }

    return plaintext;
}

/// ----------------------------------------------------------------------------
/// @brief an 8-bit permutation for SDES encryption/decryption
/// @param text (unsigned int) an 8-bit number to permute
/// @return (unsigned int) the new 8-bit number changed from bits 
///         according to SDES encryption/decryption standards
/// ----------------------------------------------------------------------------
unsigned int SDES::
initPermute(unsigned int text) {
    // The 8 bit representation:
    // k1 k2 k3 k4 k5 k6 k7 k8
    // becomes 
    // k2 k6 k3 k1 k4 k8 k5 k7
    
    // create bit masks
    unsigned int
    k1 =  0b10000000,
    k2 =  0b01000000,
    k3 =  0b00100000,
    k4 =  0b00010000,
    k5 =  0b00001000,
    k6 =  0b00000100,
    k7 =  0b00000010,
    k8 =  0b00000001;

    // grab the respectve bits and put them into their new positions 
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

/// ----------------------------------------------------------------------------
/// @brief the part of the SDES encryption/decryption where the keys are applied
///        to the message
/// @note known as the function F in notes
/// @param key (unsigned int) an 8-bit number to serve as the key (usually keyOne or keyTwo)
/// @param text (unsigned int) a 4-bit number to serve as the message to encrypt/decrypt, 
///             usually half of the message block
/// @return (unsigned int) a 4-bit number that represents the message 
///         when the given key is applied
/// ----------------------------------------------------------------------------
unsigned int SDES::
processKeyAndText(unsigned int key, unsigned int text){
    // expand the 4-bit text to 8 bits and xor with key
    unsigned int result = expandPermute4(text);
    result = result ^ key;

    if (verbose)
        cout << "The XOR of expandPermute4 and key is: " << right << setw(20) << bitset<8>(result) << endl;

    // grab left and right bits
    unsigned int leftBits = (hxF0 & result) >> 4; // shift to start at least significant bit
    unsigned int rightBits = hx0F & result;

    if (verbose) {
        cout << "Indexing S0" << "[" << (leftBits & hx1) + ((leftBits & hx9) >> 2) << "]" << "[" << ((leftBits & hx6) >> 1) << "]" <<
        " and S1" << "[" << (rightBits & hx1) + (rightBits >> 2) << "]" << "[" << ((rightBits & hx6) >> 1) << "]" << "..."<< endl;
    }

    // get new bits to use by indexing the S-boxes
    // bit representation b1 b2 b3 b4 for left/right bits
    // left bits are received by indexing S0[b1 b4][b2 b3]
    // right bits are received by indexing S1[b1 b4][b2 b3]
    unsigned int combined = 
    (S0[(leftBits & hx1) + ((leftBits & hx9) >> 2)][(leftBits & hx6) >> 1] << 2) +
    S1[(rightBits & hx1) + (rightBits >> 2)][(rightBits & hx6) >> 1];

    if (verbose)
        cout << "The combination of S0 and S1 is: " << right << setw(25) << bitset<4>(combined) << endl;

    // get the final result by permute4 the lastest combined bits
    result = permute4(combined);

    if (verbose)
        cout << "The processing of key " << bitset<8>(key) << " and text "<< bitset<4>(text) <<
        " is: " << right << setw(9) << bitset<4>(result) << endl;

    return result;
}

/// ----------------------------------------------------------------------------
/// @brief takes a 4-bit number and makes an 8-bit permutation from it
///        according to SDES encryption/decryption
/// @param bits (unsigned int) a 4-bit number to permute
/// @return (unsigned int) an 8-bit number expanded & permuted from bits
/// ----------------------------------------------------------------------------
unsigned int SDES::
expandPermute4(unsigned int bits){
    // The 4 bit representation:
    // 0  0  0  0  k1 k2 k3 k4
    // becomes 
    // k4 k1 k2 k3 k2 k3 k4 k1 

    // create bit masks
    unsigned int 
    k1 =  0b1000,
    k2 =  0b0100,
    k3 =  0b0010,
    k4 =  0b0001;

    // grab the respectve bits and put them into their new positions (with duplications)
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

/// ----------------------------------------------------------------------------
/// @brief a 4-bit permutation for SDES encryption/decryption
/// @param bits (unsigned int) a 4-bit number to permute
/// @return (unsigned int) the new 4-bit number changed according to SDES 
///         encryption/decryption
/// ----------------------------------------------------------------------------
unsigned int SDES::
permute4(unsigned int bits){
    // The 4 bit representation:
    // k1 k2 k3 k4
    // becomes 
    // k2 k4 k3 k1

    // create bit masks
    unsigned int 
    k1 =  0b1000,
    k2 =  0b0100,
    k3 =  0b0010,
    k4 =  0b0001;

    // grab the respectve bits and put them into their new positions
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

/// ----------------------------------------------------------------------------
/// @brief an 8-bit permutation to end SDES encryption/decryption, 
///        the inverse of initPermute()
/// @param text (unsigned int) an 8-bit number to permute
/// @return (unsigned int) the new 8-bit number changed from bits 
///         according to SDES encryption/decryption standards
/// ----------------------------------------------------------------------------
unsigned int SDES::
inverseInitPermute(unsigned int text){
    // The 8 bit representation:
    // k1 k2 k3 k4 k5 k6 k7 k8
    // becomes 
    // k4 k1 k3 k5 k7 k2 k8 k6
    
    // create bit masks
    unsigned int
    k1 =  0b10000000,
    k2 =  0b01000000,
    k3 =  0b00100000,
    k4 =  0b00010000,
    k5 =  0b00001000,
    k6 =  0b00000100,
    k7 =  0b00000010,
    k8 =  0b00000001;

    // grab the respectve bits and put them into their new positions
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