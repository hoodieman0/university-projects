#include "DSA.hpp"


DSA::
DSA(int p, int q, int h, int privateKey, int k) :
p(p), q(q), h(h), privateKey(privateKey), k(k) {
    g = fastModExponentiation(h, (p-1)/q, p);
    publicKey = fastModExponentiation(g, privateKey, p);
}

Signature DSA::
signHash(int hash){
    int r = fastModExponentiation(g, k, p) % q;
    
}
