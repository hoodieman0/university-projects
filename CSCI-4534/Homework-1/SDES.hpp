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
  protected:
    // encryption / decryption keys
    unsigned int keyOne = 0;
    unsigned int keyTwo = 0;

    // S-boxes used in processKeyAndText
    unsigned int S0[4][4] = {
      {0b01, 0b00, 0b11, 0b10},
      {0b11, 0b10, 0b01, 0b00},
      {0b00, 0b10, 0b01, 0b11},
      {0b11, 0b01, 0b11, 0b10}
    };
    unsigned int S1[4][4] = {
      {0b00, 0b01, 0b10, 0b11},
      {0b10, 0b00, 0b01, 0b11},
      {0b11, 0b00, 0b01, 0b00},
      {0b10, 0b01, 0b00, 0b11}
    };

    // output flags
    bool output = false;
    bool verbose = false;

    /// ----------------------------------------------------------------------------
    /// @brief Generates keyOne and keyTwo according to SDES standard
    /// @param key (unsigned int) a 10-bit key that derives keyOne and keyTwo
    /// ----------------------------------------------------------------------------
    void keyGen(unsigned int key);
    
    /// ----------------------------------------------------------------------------
    /// @brief a 10-bit permutation for SDES key generation
    ///        the first step when encoding the keys 
    /// @param bits (unsigned int) a 10-bit number to permute
    /// @return (unsigned int) the new 10-bit number changed according to SDES key
    ///         generation standards
    /// ----------------------------------------------------------------------------
    unsigned int permute10(unsigned int bits);

    /// ----------------------------------------------------------------------------
    /// @brief an 8-bit permutation for SDES key generation
    ///        the second permutation when encoding the keys 
    /// @param bits (unsigned int) an 8-bit number to permute
    /// @return (unsigned int) the new 8-bit number changed from bits 
    ///         according to SDES key generation standards
    /// ----------------------------------------------------------------------------
    unsigned int permute8(unsigned int bits);

    /// ----------------------------------------------------------------------------
    /// @brief a 5-bit left shift, where the left-most bit becomes the right-most bit
    /// @param bits (unsigned int) a 5-bit number to shift
    /// @return (unsigned int) the new 5-bit number changed from bits 
    ///         with its bits shifted left and wrapped once
    /// ----------------------------------------------------------------------------
    unsigned int leftShift(unsigned int bits);

    /// ----------------------------------------------------------------------------
    /// @brief an 8-bit permutation for SDES encryption/decryption
    /// @param text (unsigned int) an 8-bit number to permute
    /// @return (unsigned int) the new 8-bit number changed from bits 
    ///         according to SDES encryption/decryption standards
    /// ----------------------------------------------------------------------------
    unsigned int initPermute(unsigned int text);
    
    /// ----------------------------------------------------------------------------
    /// @brief the part of the SDES encryption/decryption where the keys are applied
    ///        to the message
    /// @param key (unsigned int) an 8-bit number to serve as the key (usually keyOne or keyTwo)
    /// @param text (unsigned int) a 4-bit number to serve as the message to encrypt/decrypt, 
    ///             usually half of the message block
    /// @return (unsigned int) a 4-bit number that represents the message 
    ///         when the given key is applied
    /// ----------------------------------------------------------------------------
    unsigned int processKeyAndText(unsigned int key, unsigned int text);
    
    /// ----------------------------------------------------------------------------
    /// @brief takes a 4-bit number and makes an 8-bit permutation from it
    ///        according to SDES encryption/decryption
    /// @param bits (unsigned int) a 4-bit number to permute
    /// @return (unsigned int) an 8-bit number expanded & permuted from bits
    /// ----------------------------------------------------------------------------
    unsigned int expandPermute4(unsigned int bits);

    /// ----------------------------------------------------------------------------
    /// @brief a 4-bit permutation for SDES encryption/decryption
    /// @param bits (unsigned int) a 4-bit number to permute
    /// @return (unsigned int) the new 4-bit number changed according to SDES 
    ///         encryption/decryption
    /// ----------------------------------------------------------------------------
    unsigned int permute4(unsigned int bits);

    /// ----------------------------------------------------------------------------
    /// @brief an 8-bit permutation to end SDES encryption/decryption, 
    ///        the inverse of initPermute()
    /// @param text (unsigned int) an 8-bit number to permute
    /// @return (unsigned int) the new 8-bit number changed from bits 
    ///         according to SDES encryption/decryption standards
    /// ----------------------------------------------------------------------------
    unsigned int inverseInitPermute(unsigned int text);

  public:
    /// ----------------------------------------------------------------------------
    /// @brief SDES class constructor
    /// @param key (unsigned int) a 10-bit number that serves as the encryption key
    /// @param output (bool) flag to send homework outputs to console
    /// @param verbose (bool) flag to send debugging outputs to console
    /// ----------------------------------------------------------------------------
    SDES(const unsigned int key, bool output=false, bool verbose=false);
    ~SDES() = default;

    /// ----------------------------------------------------------------------------
    /// @brief the SDES encryption algorithm to obscure information
    /// @param plaintext (unsigned int) the 8-bit number considered as the message
    /// @return (unsigned int) the 8-bit number cipher text using keyOne and keyTwo
    /// ----------------------------------------------------------------------------
    unsigned int encrypt(const unsigned int plaintext);

    /// ----------------------------------------------------------------------------
    /// @brief the SDES decryption algorithm to read obscured information
    /// @param ciphertext (unsigned int) the 8-bit number considered as the cipher text
    /// @return (unsigned int) the 8-bit number plain text using keyTwo and keyOne
    /// ----------------------------------------------------------------------------
    unsigned int decrypt(const unsigned int ciphertext);
};

#endif