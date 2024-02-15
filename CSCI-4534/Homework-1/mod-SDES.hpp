#ifndef MOD_SDES_HPP
#define MOD_SDES_HPP

#include "SDES.hpp"

class modSDES : public SDES {
    protected:
        // modified S-box used in processKeyAndText
        unsigned int S1p[4][4] = {
            {0b10, 0b00, 0b01, 0b11},
            {0b00, 0b01, 0b10, 0b11},
            {0b11, 0b00, 0b01, 0b00},
            {0b10, 0b01, 0b00, 0b11}
        };
        
        /// ----------------------------------------------------------------------------
        /// @brief the part of the SDES encryption/decryption where the keys are applied
        ///        to the message
        /// @param key (unsigned int) an 8-bit number to serve as the key (usually keyOne or keyTwo)
        /// @param text (unsigned int) a 4-bit number to serve as the message to encrypt/decrypt, 
        ///             usually half of the message block
        /// @return (unsigned int) a 4-bit number that represents the message 
        ///         when the given key is applied
        /// ----------------------------------------------------------------------------
        unsigned int modProcessKeyAndText(unsigned int key, unsigned int text);

    public:
        /// ----------------------------------------------------------------------------
        /// @brief mod-SDES class constructor
        /// @param key (unsigned int) a 10-bit number that serves as the encryption key
        /// @param output (bool) flag to send homework outputs to console
        /// @param verbose (bool) flag to send debugging outputs to console
        /// ----------------------------------------------------------------------------
        modSDES(unsigned int key, bool output=false, bool verbose=false) : SDES(key, output, verbose) {}
        ~modSDES() = default;

        /// ----------------------------------------------------------------------------
        /// @brief the SDES encryption algorithm to encrypt information
        /// @param plaintext (unsigned int) the 8-bit number considered as the message to encrypt
        /// @return (unsigned int) the 8-bit number cipher text using keyOne and keyTwo
        /// ----------------------------------------------------------------------------
        unsigned int modEncrypt(const unsigned int plaintext);

        /// ----------------------------------------------------------------------------
        /// @brief the SDES decryption algorithm to read encrypted information
        /// @param ciphertext (unsigned int) the 8-bit number considered as the cipher text to decrypt
        /// @return (unsigned int) the 8-bit number plain text using keyTwo and keyOne
        /// ----------------------------------------------------------------------------
        unsigned int modDecrypt(const unsigned int ciphertext);
        
};

#endif