#include "DSA.hpp"

DSA::
DSA(int p, int q, int h, int privateKey) :
p(p), q(q), h(h), privateKey(privateKey) {
    g = fastModExponentiation(h, (p-1)/q, p);
    publicKey = fastModExponentiation(g, privateKey, p);
}

Signature DSA::
signHash(const int hash, const int k) const{
    int r = fastModExponentiation(g, k, p) % q;
    int inverseK = modInverse(k, q);
    int s = (inverseK * (hash + (privateKey * r))) % q; 
    return Signature {
        r,
        s
    };
}

bool DSA::
verifyHash(const int hash, const Signature sig) const{
    int w = modInverse(sig.s, q);
    int u1 = (hash * w) % q;
    int u2 = (sig.r * w) % q;
    int v = (fastModExponentiation(g, u1, p) * fastModExponentiation(publicKey, u2, p)) % q;
    return v == sig.r;
}