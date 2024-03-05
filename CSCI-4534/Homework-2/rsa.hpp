#ifndef RSA_HPP
#define RSA_HPP

#include <random>
#include <iostream>

using namespace std;

#define TEST_REPEAT 1000

struct Key{
    int key;
    int number;    // must be larger than message size
};

class RSA {
private:
    int primeP;
    int primeQ;
    
    Key publicKey;
    Key privateKey;

    // calculates the Euler Totient of two primes
    int eulerTotient(int p, int q) const { return (p-1)*(q-1); }

    int gcd(int a, int b) { int _; return gcdExtended(a, b, &_, &_); }

    // check if selected P and Q are prime
    bool isPrime(int num);
    bool isPrimeMillerRabin(int num, int repeat);
    bool compositeWitness(int a, int num);

    // get inverse from modLinearEquationSolver
    int modInverse(int a, int n) const;

    // ax = b mod n, find x
    int modLinearEquationSolver(int a, int b, int n) const;

    // Extended Euclidian Algorithm for GCD 
    int gcdExtended(int a, int b, int* x, int* y) const;

    // a ^ b mod n but fast
    int fastModExponentiation(int a, int b, int n) const;

public:
    RSA();
    ~RSA()=default;
    bool test() { return compositeWitness(137, 221); }

    const Key getPublicKey() { return publicKey; }

    // make new keys for class
    void generateKeys();

    // encrypt with own public key
    int encrypt(int plaintext) const;

    // decrypt with own private key
    int decrypt(int plaintext) const;
};

#endif 