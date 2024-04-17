#include "DSA.hpp"

DSA::
DSA(int p, int q, int h, int privateKey, bool verbose, bool output) :
p(p), q(q), h(h), privateKey(privateKey), verbose(verbose), output(output) {
    g = fastModExponentiation(h, (p-1)/q, p);
    publicKey = fastModExponentiation(g, privateKey, p);

    if (verbose || output){
        cout << "g:             " << g << endl;
        cout << "publicKey:     " << publicKey << endl;
    }
}

Signature DSA::
signHash(const int hash, const int k) const{
    int r = fastModExponentiation(g, k, p) % q;
    int inverseK = modInverse(k, q);
    int s = (inverseK * (hash + (privateKey * r))) % q; 

    if (verbose || output){
        cout << "r:     " << r << endl;
        cout << "s:     " << s << endl;
    }

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

    if (verbose || output){
        cout << "w:         " << w << endl;
        cout << "u1:        " << u1 << endl;
        cout << "u2:        " << u2 << endl;
        cout << "v:         " << v << endl;
        cout << "v == r:    " << boolalpha << (v == sig.r) << endl;
    }
    return v == sig.r;
}