#include "mod-SDES.hpp"

/// ----------------------------------------------------------------------------
/// @brief the SDES encryption algorithm to encrypt information
/// @param plaintext (unsigned int) the 8-bit number considered as the message to encrypt
/// @return (unsigned int) the 8-bit number cipher text using keyOne and keyTwo
/// ----------------------------------------------------------------------------
unsigned int modSDES::
modEncrypt(const unsigned int plaintext){
    // IP -> F w/ K1 -> SW -> F w/ K2 -> inverseIP 
    
    if (output || verbose)
        cout << "----------------------------------------------------------\n" << 
        "encrypt():" << endl;

    // permute the initial bits through IP and separate left and right bits
    unsigned int result = initPermute(plaintext);
    unsigned int leftBits = (result & hxF0) >> 4; // keep start at least significant bit
    unsigned int rightBits = result & hx0F;

    // grab bits to xor the left bits
    result = modProcessKeyAndText(keyOne, rightBits);
    leftBits = leftBits ^ result;

     // swap left and right bits here
    result = (rightBits << 4) + leftBits; // this line is used for outputs

    if (verbose)
        cout << "Swapping left and right bits..." << endl;
    if (output || verbose)
        cout << "The intermediate value after the SW operation is: " <<
        right << setw(0) << bitset<8>(result) << endl;

    // grab bits to xor with right bits (after swap)
    result = modProcessKeyAndText(keyTwo, leftBits);
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
/// @brief the SDES decryption algorithm to read encrypted information
/// @param ciphertext (unsigned int) the 8-bit number considered as the cipher text to decrypt
/// @return (unsigned int) the 8-bit number plain text using keyTwo and keyOne
/// ----------------------------------------------------------------------------
unsigned int modSDES::
modDecrypt(const unsigned int ciphertext){
        // IP -> F w/ K2 -> SW -> F w/ K1 -> inverseIP 

    if (output|| verbose)
        cout << "----------------------------------------------------------\n" << 
        "decrypt():" << endl;

    // permute the initial bits through IP and separate left and right bits
    unsigned int result = initPermute(ciphertext);
    unsigned int leftBits = (result & hxF0) >> 4; // keep start at least significant bit
    unsigned int rightBits = result & hx0F;

    // grab bits to xor the left bits
    result = modProcessKeyAndText(keyTwo, rightBits);
    leftBits = leftBits ^ result;

    // swap left and right bits here
    result = (rightBits << 4) + leftBits; // this line is used for outputs

    if (verbose)
        cout << "Swapping left and right bits..." << endl;
    if (output || verbose)
        cout << "The intermediate value after the SW operation is: " <<
        right << setw(0) << bitset<8>(result) << endl;

    // grab bits to xor with right bits (after swap)
    result = modProcessKeyAndText(keyOne, leftBits);
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
/// @brief the part of the SDES encryption/decryption where the keys are applied
///        to the message
/// @note known as the function F in notes, but uses S1p instead of S1
/// @param key (unsigned int) an 8-bit number to serve as the key (usually keyOne or keyTwo)
/// @param text (unsigned int) a 4-bit number to serve as the message to encrypt/decrypt, 
///             usually half of the message block
/// @return (unsigned int) a 4-bit number that represents the message 
///         when the given key is applied
/// ----------------------------------------------------------------------------
unsigned int modSDES::
modProcessKeyAndText(unsigned int key, unsigned int text){
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
        " and S1p" << "[" << (rightBits & hx1) + (rightBits >> 2) << "]" << "[" << ((rightBits & hx6) >> 1) << "]" << "..."<< endl;
    }

    // get new bits to use by indexing the S-boxes
    // bit representation b1 b2 b3 b4 for left/right bits
    // left bits are received by indexing S0[b1 b4][b2 b3]
    // right bits are received by indexing S1p[b1 b4][b2 b3]
    unsigned int combined = 
    (S0[(leftBits & hx1) + ((leftBits & hx9) >> 2)][(leftBits & hx6) >> 1] << 2) +
    S1p[(rightBits & hx1) + (rightBits >> 2)][(rightBits & hx6) >> 1];

    if (verbose)
        cout << "The combination of S0 and S1p is: " << right << setw(24) << bitset<4>(combined) << endl;

    // get the final result by permute4 the lastest combined bits
    result = permute4(combined);

    if (verbose)
        cout << "The processing of key " << bitset<8>(key) << " and text "<< bitset<4>(text) <<
        " is: " << right << setw(9) << bitset<4>(result) << endl;

    return result;
}