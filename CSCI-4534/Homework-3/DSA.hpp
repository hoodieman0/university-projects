#ifndef DSA_HPP
#define DSA_HPP

#include <iostream>
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
    bool verbose, output;

public:
    DSA(int p, int q, int h, int privateKey, bool verbose = false, bool output = false);
    Signature signHash(const int hash, const int k) const;
    bool verifyHash(const int hash, const Signature sig) const;

    ~DSA()=default;
};

#endif