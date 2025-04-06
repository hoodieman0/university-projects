#include "RSA.hpp"

/// -----------------------------------------------------------------------------------------------------------
/// @brief constructor for the RSA class
/// -----------------------------------------------------------------------------------------------------------
RSA::
RSA(){
    generateKeys();
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief helper function to generate a new set of keys and primes 
/// -----------------------------------------------------------------------------------------------------------
void RSA::
generateKeys(){
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> dist(10, 100);
    
    // select primes where P != Q and both are between 10 & 100
    do {
        primeP = dist(e1);
    } while (!isPrime(primeP));
    
    do {
        primeQ = dist(e1);
    } while (!isPrime(primeQ) || primeQ == primeP);

    // compute number & totient
    int n = primeP * primeQ;
    publicKey.number = n;
    privateKey.number = n;

    int totient = eulerTotient(primeP, primeQ);

    // choose encryption key between 2 & totient - 1 and where GCD(public key, totient) == 1
    // and private key is modular inverse of public key 
    uniform_int_distribution<int> keyGen(2, totient - 1);
    do {
        do {
        publicKey.key = keyGen(e1);
        } while (gcd(publicKey.key, totient) != 1);

        try { privateKey.key = modInverse(publicKey.key, totient); } // choose private key to be modular inverse of pubkey
        catch (...){ privateKey.key = 0; }
    } while (publicKey.key == 0 || publicKey.key < 0 || privateKey.key == 0 || privateKey.key < 0);
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief     probablistically (monte carlo) determines if a number is prime or not
/// @param num (int) the number to test if it is prime
/// @return    (bool) true if prime, false if composite
/// -----------------------------------------------------------------------------------------------------------
bool RSA::
isPrime(int num){
    if (num <= 1) return false;                     // num is 1 or smaller
    if (num <= 3) return true;                      // num is 2 or 3
    if (num % 2 == 0 || num % 3 == 0) return false; // num is divisible by 2 or 3
    
    return isPrimeMillerRabin(num, TEST_REPEAT);    // run Miller Rabin test TEST_REPEAT times
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief        a monte carlo probablistic approach to determine if a number is prime
/// @param num    (int) the number to see if it is prime
/// @param repeat (int) the number of times to repeat the Miller Rabin test
/// @return       (bool) true if num is prime, false if composite
/// @note         running this 10 times there is less than 0.000001% chance it is wrong
/// -----------------------------------------------------------------------------------------------------------
bool RSA::
isPrimeMillerRabin(int num, int repeat){
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> dist(1, num - 1);
    
    int a;
    for (int i = 0; i < repeat; i++){
        a = dist(e1);                   // generate a base between 1 and num - 1
        try {
            if (compositeWitness(a, num)) return false; // if base is a composite witness of num, return false
        }
        catch (const char * txt) {
            cout << txt << endl;        // catch if a can't be used in fast mod exponentiation
        } catch (...) {}
    }

    return true;
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief      check if a number is a composite of another number
/// @example    21 is a composite witness of 63, 22 is not
/// @note       comes from Introduction to Algorithms, Cormen Leiserson, Rivest, MIT Press 0262033844
/// @param a    (int) number to see if it is a composite witness of num
/// @param num  (int) the number to test against, usualy a likely prime number
/// @return     (bool) true if a is a composite witness of num, false otherwise
/// -----------------------------------------------------------------------------------------------------------
bool RSA::
compositeWitness(int a, int num){
    // num - 1 = (2^t) * u
    // t is the number of exponents to use in fastMod
    // u is an odd number to use as an initial exponent
    int t = 0, u = num - 1; // this could be calculated once in another function
    while (u % 2 == 0){
        u /= 2;
        t++;
    }

    int temp = 0;                               // keep track of the previous value
    int x = fastModExponentiation(a, u, num);   // a^u mod num

    for (int i = 0; i <= t; i++){
        temp = x;
        x = fastModExponentiation(x, 2, num);   // x^2 mod num

        if (x == 1 && temp != 1 && temp != num - 1) {
            return true;        // num is composite
        }
    }

    if (x != 1) return true;    // num is composite
    
    return false;               // num is not composite
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief      helper function to calculate modular inverse, ax = 1 mod n from modLinearEquationSolver
/// @param a    (int) positive known term in the above equation
/// @param n    (int) modulus value of the equation 
/// @return     (int) modular inverse of a mod n 
/// @throw      if the modular inverse cannot be found, a const char* message notification is thrown
/// -----------------------------------------------------------------------------------------------------------
int RSA::
modInverse(int a, int n) const {
    return modLinearEquationSolver(a, 1, n);
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief      uses the extended Euclidean algorithm to find the solution to ax = b mod n
/// @param a    (int) positive known term in the above equation
/// @param b    (int) positive congruent term in the above equation
/// @param n    (int) modulus value of the equation 
/// @return     (int) the solution x to the equation ax = b mod n
/// @throw      if the modular inverse cannot be found, a const char* message notification is thrown
/// -----------------------------------------------------------------------------------------------------------
int RSA::
modLinearEquationSolver(int a, int b, int n) const {
    int x,              // first Bezout coefficient from gcdExtended
        y;              // second Bezout coefficient from gcdExtended

    int gcd = gcdExtended(a, n, &x, &y);    // get the greatest common denominator and the Bezout coefficients
    if (b % gcd == 0){
        return ((x % n + n) % n);           // make sure solution x is within modulus range and return it
    }

    throw "Modular Linear Equation Solver cannot return a value";
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief      the extended Euclidean algorithm to find the greatest common denominator
///             where remainder = ax + by = GCD(a, b)
/// @param a    (int) the first term to find the GCD with
/// @param b    (int) the second term to find the GCD with
/// @param x    (int*) return parameter to return Bezout coefficient x
/// @param y    (int*) return parameter to return Bezout coefficient y
/// @return     (int) the GCD of a & b, as well as Bezout coefficients in x & y
/// @cite       https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Pseudocode
/// @date       4 Mar 2024
/// -----------------------------------------------------------------------------------------------------------
int RSA::
gcdExtended(int a, int b, int* x, int* y) const{
    int remainder   = a, newRemainder   = b;   
    int bezoutX     = 1, bezoutXCalc    = 0;
    int bezoutY     = 0, bezoutYCalc    = 1;
    int quotient    = 0, temp           = 0;

    while (newRemainder != 0){                                  // while there is something to divide
        quotient = remainder / newRemainder;                    // get the quotient result
        temp = newRemainder;
        newRemainder = remainder - (quotient * newRemainder);   // calculate next remainder
        remainder = temp; 

        temp = bezoutXCalc;
        bezoutXCalc = bezoutX - (quotient * bezoutXCalc);       // calculate next x Bezout coefficient
        bezoutX = temp;

        temp = bezoutYCalc;
        bezoutYCalc = bezoutY - (quotient * bezoutYCalc);       // calculate next y Bezout coefficient
        bezoutY = temp;
    }

    // cout << "Quotients of GCD: (" << bezoutYCalc << ", " << bezoutXCalc << ")" << endl;
    // cout << "Final GCD: " << remainder << endl;
    // cout << "Bezout coefficients: (" bezoutX << ", " << bezoutY << ")" << endl;

    *x = bezoutX; *y = bezoutY;                                 // assign return parameters and return GCD
    return remainder;
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief              encrypts the given plaintext with the object's public key
/// @param plaintext    (int) the plaintext to encrypt
/// @return             (int) the ciphertext of the encryption
/// -----------------------------------------------------------------------------------------------------------
int RSA::
encrypt(int plaintext) const {
    return fastModExponentiation(plaintext, publicKey.key, publicKey.number);
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief              decrypts the given ciphertext with the object's private key
/// @param ciphertext   (int) the ciphertext to decrypt
/// @return             (int) the plaintext of the decryption
/// -----------------------------------------------------------------------------------------------------------
int RSA::
decrypt(int ciphertext) const {
    return fastModExponentiation(ciphertext, privateKey.key, privateKey.number);
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief      solve a ^ b mod n fast using less multiplications
/// @param a    (int) positive base of the equation
/// @param b    (int) positive exponent of the equation
/// @param n    (int) modulus value of the equation
/// @return     (int) result of a ^ b mod n
/// @note       relies on the idea that modding smaller parts gets same result
/// @example    a^5 mod n = a^2 mod n * a^2 mod n * a mod n
/// -----------------------------------------------------------------------------------------------------------
int RSA::
fastModExponentiation(int a, int b, int n) const {
    int result = 1;
    a = a % n;
    
    while (b > 0){
        if (b & 1) result = (result * a) % n;       // if b is odd, set the new result and mod it by n (result * [a mod n])
        b >>= 1;                                    // another a^2 mod n is added, divide exponent b by 2
        a = (a * a) % n;                            // a = a^2 mod n
    }

    return result;
}