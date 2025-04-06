#ifndef DSA_HPP
#define DSA_HPP

#include <iostream>
#include "Cryptography.hpp"

using namespace std;

// see powerpoint for naming convention

struct Signature {
    int r;
    int s;
};

class DSA {
private:
    // privateKey = x, publicKey = y
    int p, q, h, privateKey;    // globally known
    int publicKey, g;           // derived
    bool verbose, output;       // output flags

public:
    /// ----------------------------------------------------------------------------
    /// @brief constructor for the DSA class, generates g & public key
    /// @param p (int) a prime number
    /// @param q (int) a factor of (p-1)
    /// @param h (int) a chosen number between 0 and p-1, and fastModExponentiation(h, (p-1)/q, p) > 1
    /// @param privateKey (int) a number between 0 and q
    /// @param verbose (bool) a flag to show debugging information
    /// @param output (bool) a flag to show homework outputs
    /// ----------------------------------------------------------------------------
    DSA(int p, int q, int h, int privateKey, bool verbose = false, bool output = false);
    
    /// ----------------------------------------------------------------------------
    /// @brief calcuates the signature values r & s for the given hash and random number
    /// @param hash (int) the hash of a message
    /// @param k (int) a random number < q
    /// @return (Signature) the r & s values for hash and k
    /// ----------------------------------------------------------------------------
    Signature signHash(const int hash, const int k) const;

    /// ----------------------------------------------------------------------------
    /// @brief verifies that the signature matches the given hash
    /// @param hash (int) the hash of a message
    /// @param sig (Signature) the r & s values for the signature
    /// @return (bool) true if the signature is paired with hash, otherwise false
    /// ----------------------------------------------------------------------------
    bool verifyHash(const int hash, const Signature sig) const;

    ~DSA()=default;
};

#endif