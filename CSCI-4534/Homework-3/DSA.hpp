#ifndef DSA_HPP
#define DSA_HPP

#include "Cryptography.hpp"

using namespace std;

struct Signature {
    int r;
    int s;
};

class DSA {
    private:
    // privateKey = x, publicKey = y
    int p, q, h, privateKey;    // globally known
    int publicKey, g;           // derived

    public:
    DSA(int p, int q, int h, int privateKey);
    Signature signHash(int hash, int k) const;
    bool verifyHash(const int hash, const Signature sig) const;

    ~DSA()=default;
};

#endif