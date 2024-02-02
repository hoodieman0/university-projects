#ifndef SDES_HPP
#define SDES_HPP

// bit masks used for keyGen()
#define hx2E0 0b1111100000
#define hx01F 0b0000011111

// bit masks used for encrypt()/decrypt()
#define hx0F 0b00001111
#define hxF0 0b11110000

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

    // P10 -> SHIFT -> P8 -> keyOne
    // P10 -> SHIFT -> SHIFT-> P8 -> keyOne
    void keyGen(unsigned int key);
    unsigned int permute10(unsigned int bits);
    unsigned int permute8(unsigned int bits);
    unsigned int leftShift(unsigned int bits);

    void IP();
    void inverseIP();
    
    void P8();
    void SW();
    void smallF();
    void F();
    void S0();

  public:
    SDES(const unsigned int key, bool output=false, bool verbose=false);
    ~SDES() = default;

    // IP -> smallF w/ K1 -> SW -> smallF w/ K2 -> inverseIP 
    unsigned int encrypt(const unsigned int plaintext);

    // IP -> smallF w/ K2 -> SW -> smallF w/ K1 -> inverseIP 
    unsigned int decrypt(const unsigned int ciphertext);
};

#endif