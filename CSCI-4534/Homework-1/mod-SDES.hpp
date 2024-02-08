#ifndef MOD_SDES_HPP
#define MOD_SDES_HPP

#include "SDES.hpp"

class modSDES : public SDES {
    protected:
        unsigned int S1p[4][4] = {
            {0b10, 0b00, 0b01, 0b11},
            {0b00, 0b01, 0b10, 0b11},
            {0b11, 0b00, 0b01, 0b00},
            {0b10, 0b01, 0b00, 0b11}
        };

        unsigned int modProcessKeyAndText(unsigned int key, unsigned int text);

    public:
        modSDES(unsigned int key, bool output=false, bool verbose=false) : SDES(key, output, verbose) {}
        ~modSDES() = default;
        unsigned int modEncrypt(const unsigned int plaintext);
        unsigned int modDecrypt(const unsigned int ciphertext);
        
};

#endif