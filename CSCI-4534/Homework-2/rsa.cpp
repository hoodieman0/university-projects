#include "RSA.hpp"

RSA::
RSA(){
    generateKeys();
}

void RSA::
generateKeys(){
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> dist(10, 100);
    
    // select primes
    do {
        primeP = dist(e1);
    } while (!isPrime(primeP));
    
    do {
        primeQ = dist(e1);
    } while (!isPrime(primeQ));

    // compute number & totient
    int n = primeP * primeQ;
    publicKey.number = n;
    privateKey.number = n;

    int totient = eulerTotient(primeP, primeQ);

    cout << "totient: " << totient << endl;
    cout << "P: " << primeP << endl;
    cout << "Q: " << primeQ << endl;
    cout << "N: " << n << endl;

    // choose encryption key
    uniform_int_distribution<int> keyGen(2, totient - 1);
    do {
        publicKey.key = keyGen(e1);
        // gcd

        try { privateKey.key = modInverse(publicKey.key, totient); } // choose private key to be modular inverse of pubkey
        catch (...){ privateKey.key = 0; }
    } while (publicKey.key == 0 || publicKey.key < 0 || privateKey.key == 0 || privateKey.key < 0);

    cout << publicKey.key << endl;
    cout << privateKey.key << endl;
}

bool RSA::
isPrime(int num){
    if (num <= 1) return false;                     // num is 1 or smaller
    if (num <= 3) return true;                      // num is 2 or 3
    if (num % 2 == 0 || num % 3 == 0) return false; // num is divisible by 2 or 3
    
    return isPrimeMillerRabin(num, TEST_REPEAT);
}

// monte carlo
bool RSA::
isPrimeMillerRabin(int num, int repeat){
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> dist(1, num - 1);

    int a;
    for (int i = 0; i < repeat; i++){
        a = dist(e1);
        try {
            if (compositeWitness(a, num)) return false;
        }
        catch (const char * txt) {
            cout << txt << endl;
        } catch (...) {}
    }

    return true;
}

// is a a composite witness of num
bool RSA::
compositeWitness(int a, int num){
    int t = 0, u = num - 1; // this only needs to be calculated once
    while (u % 2 == 0){
        u /= 2;
        t++;
    }

    int temp = 0;
    int x = fastModExponentiation(a, u, num);


    for (int i = 0; i <= t; i++){
        temp = x;
        x = fastModExponentiation(x, 2, num);

        if (x == 1 && temp != 1 && temp != num - 1) {
            return true;        // num is composite
        }
    }

    if (x != 1) return true;    // num is composite
    
    return false;   // num is not composite
}

int RSA::
modInverse(int a, int n) const {
    return modLinearEquationSolver(a, 1, n);
}

int RSA::
modLinearEquationSolver(int a, int b, int n) const {
    int gcd; 
    int x,          // first coefficient from gcdExtended
    y;              // second coefficient from gcdExtended
    gcd = gcdExtended(a, n, &x, &y);
    cout << "GCD: " << gcd << endl;
    if (b % gcd == 0){
        return (x * (b/gcd)) % n;
    }

    throw "Modular Linear Equation Solver cannot return a value";
}

// find a solution such that result = ax + by = GCD(a, b)
int RSA::
gcdExtended(int a, int b, int* x, int* y) const{
    if (b == 0){
        *x = 1;
        *y = 0;
        return a;
    }

    int result = gcdExtended(b, a % b, x, y);
    int temp = *x;
    *x = *y;
    *y = temp - (a / b) * (*y);
    return result;
}

int RSA::
encrypt(int plaintext) const {
    return fastModExponentiation(plaintext, publicKey.key, publicKey.number);
}

int RSA::
decrypt(int ciphertext) const {
    return fastModExponentiation(ciphertext, privateKey.key, privateKey.number);
}

// solve a^b mod n fast
// uses less multiplications for mod operations
// relies on the idea that modding smaller parts gets same result
// for example: a^5 mod n = a^2 mod n * a^2 mod n * a mod n
int RSA::
fastModExponentiation(int a, int b, int n) const {
    int i = b;
    int x = a % n;
    int result = 1;
    while ( i > 0){
        if (i & 1) result = (result * x) % n;       // if b is odd, set the new result and mod it by n
        i >>= 1;                                    // divide by 2
        x = (x * x) % n;                            // a^2 mod n
    }

    return result;
}