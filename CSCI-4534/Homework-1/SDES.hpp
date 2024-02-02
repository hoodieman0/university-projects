#ifndef SDES_HPP
#define SDES_HPP

// bit masks used for keyGen()
#define hx2E0 0b1111100000
#define hx01F 0b0000011111

// bit masks used for encrypt()/decrypt()
#define hxF0 0b11110000
#define hx0F 0b00001111

// bit masks used for processKeyAndText()
#define hx9 0b1001
#define hx6 0b0110
#define hx1 0b0001


#include <string>
#include <iostream>
#include <iomanip>
#include <bitset>

using namespace std;

class SDES {
  private:
    unsigned int keyOne = 0;
    unsigned int keyTwo = 0;

    bool output = false;
    bool verbose = false;

    void keyGen(unsigned int key);
    unsigned int permute10(unsigned int bits);
    unsigned int permute8(unsigned int bits);
    unsigned int leftShift(unsigned int bits);

    unsigned int initPermute(unsigned int text);
    // Fk
    unsigned int processKeyAndText(unsigned int key, unsigned int text);
    unsigned int inverseInitPermute(unsigned int text);

  public:
    SDES(const unsigned int key, bool output=false, bool verbose=false);
    ~SDES() = default;

    // IP -> smallF w/ K1 -> SW -> smallF w/ K2 -> inverseIP 
    unsigned int encrypt(const unsigned int plaintext);

    // IP -> smallF w/ K2 -> SW -> smallF w/ K1 -> inverseIP 
    unsigned int decrypt(const unsigned int ciphertext);
};

#endif