//
// Created by hoodi on 10/25/2022.
//

#ifndef RSA_HPP
#define RSA_HPP

#include "tools.hpp"
#include "PubKey.hpp"

#define BT int

class RSA {
private:
    BT primeP = 0;
    BT primeQ = 0;
    BT number = 0; //longer than chars in file (otherwise split BTo blocks)
    BT pubKey = 0;
    BT priKey = 0;

    static BT GCD(BT, BT);
    static bool isRelativePrime(BT, BT);
    static BT fastMod(BT, BT, BT);
    static bool millerTest(BT, BT);
    static bool isPrime(BT, int); //TODO revamp
    //p and q must be prime
    static BT eulerTotient(BT p, BT q) { return (p-1) * (q-1);}
    static BT extendedEuclid(BT, BT, BT*, BT*);
    static BT modLinear(BT, BT, BT); //for this purpose, has a unique value

public:
    RSA();
    ~RSA() = default;
    void generateKeys();
    void encryptFile(const string&) const;
    void decryptFile(const string&) const;
    PubKey getPubKey() const;
};


#endif
