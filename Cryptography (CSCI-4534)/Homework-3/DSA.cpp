#include "DSA.hpp"

/// ----------------------------------------------------------------------------
/// @brief constructor for the DSA class, generates g & public key
/// @param p (int) a prime number
/// @param q (int) a factor of (p-1)
/// @param h (int) a chosen number between 0 and p-1, and fastModExponentiation(h, (p-1)/q, p) > 1
/// @param privateKey (int) a number between 0 and q
/// @param verbose (bool) a flag to show debugging information
/// @param output (bool) a flag to show homework outputs
/// ----------------------------------------------------------------------------
DSA::
DSA(int p, int q, int h, int privateKey, bool verbose, bool output) :
p(p), q(q), h(h), privateKey(privateKey), verbose(verbose), output(output) {
    g = fastModExponentiation(h, (p-1)/q, p);               // h ^ ([p-1]/q) mod p
    publicKey = fastModExponentiation(g, privateKey, p);    // g ^ x mod p

    if (verbose || output){
        cout << "g:             " << g << endl;
        cout << "publicKey:     " << publicKey << endl;
    }
}

/// ----------------------------------------------------------------------------
/// @brief calcuates the signature values r & s for the given hash and random number
/// @param hash (int) the hash of a message
/// @param k (int) a random number < q
/// @return (Signature) the r & s values for hash and k
/// ----------------------------------------------------------------------------
Signature DSA::
signHash(const int hash, const int k) const{
    int r = fastModExponentiation(g, k, p) % q;             // (g ^ k mod p) mod q
    int inverseK = modInverse(k, q);                        // k^-1 mod q
    int s = (inverseK * (hash + (privateKey * r))) % q;     // [k^-1 (hash + privateKey * r)] mod q

    if (verbose || output){
        cout << "r:     " << r << endl;
        cout << "s:     " << s << endl;
    }

    return Signature {
        r,
        s
    };
}

/// ----------------------------------------------------------------------------
/// @brief verifies that the signature matches the given hash
/// @param hash (int) the hash of a message
/// @param sig (Signature) the r & s values for the signature
/// @return (bool) true if the signature is paired with hash, otherwise false
/// ----------------------------------------------------------------------------
bool DSA::
verifyHash(const int hash, const Signature sig) const{
    int w = modInverse(sig.s, q);
    int u1 = (hash * w) % q;
    int u2 = (sig.r * w) % q;
    int v = ((fastModExponentiation(g, u1, p) * fastModExponentiation(publicKey, u2, p)) % p)  % q;

    if (verbose || output){
        cout << "w:         " << w << endl;
        cout << "u1:        " << u1 << endl;
        cout << "u2:        " << u2 << endl;
        cout << "v:         " << v << endl;
        cout << "v == r:    " << boolalpha << (v == sig.r) << endl;
    }
    return v == sig.r;
}