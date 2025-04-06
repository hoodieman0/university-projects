#ifndef RSA_HPP
#define RSA_HPP

#include <random>
#include <iostream>

using namespace std;

#define TEST_REPEAT 1000

/// @brief holds either the public key or private key information of RSA
struct Key{
    int key;
    int number;    // must be larger than message size
};

class RSA {
private:
    // generated primes for number N
    int primeP;
    int primeQ;
    
    // generated RSA keys
    Key publicKey;
    Key privateKey;

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief      calculate the euler totient of two primes
    /// @param p    (int) a prime number
    /// @param q    (int) a prime number
    /// @return     (int) the euler totient
    /// -----------------------------------------------------------------------------------------------------------
    int eulerTotient(int p, int q) const { return (p-1)*(q-1); }

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief      a helper function to get the greatest common denominator of two numbers
    /// @param a    (int) any number
    /// @param b    (int) any number
    /// @return     (int) the GCD of a and b
    /// -----------------------------------------------------------------------------------------------------------
    int gcd(int a, int b) { int _; return gcdExtended(a, b, &_, &_); }

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief     probablistically (monte carlo) determines if a number is prime or not
    /// @param num (int) the number to test if it is prime
    /// @return    (bool) true if prime, false if composite
    /// -----------------------------------------------------------------------------------------------------------
    bool isPrime(int num);

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief        a monte carlo probablistic approach to determine if a number is prime
    /// @param num    (int) the number to see if it is prime
    /// @param repeat (int) the number of times to repeat the Miller Rabin test
    /// @return       (bool) true if num is prime, false if composite
    /// @note         running this 10 times there is less than 0.000001% chance it is wrong
    /// -----------------------------------------------------------------------------------------------------------
    bool isPrimeMillerRabin(int num, int repeat);

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief      check if a number is a composite of another number
    /// @example    21 is a composite witness of 63, 22 is not
    /// @note       comes from Introduction to Algorithms, Cormen Leiserson, Rivest, MIT Press 0262033844
    /// @param a    (int) number to see if it is a composite witness of num
    /// @param num  (int) the number to test against, usualy a likely prime number
    /// @return     (bool) true if a is a composite witness of num, false otherwise
    /// -----------------------------------------------------------------------------------------------------------
    bool compositeWitness(int a, int num);

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief      helper function to calculate modular inverse, ax = 1 mod n from modLinearEquationSolver
    /// @param a    (int) positive known term in the above equation
    /// @param n    (int) modulus value of the equation 
    /// @return     (int) modular inverse of a mod n 
    /// @throw      if the modular inverse cannot be found, a const char* message notification is thrown
    /// -----------------------------------------------------------------------------------------------------------
    int modInverse(int a, int n) const;

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief      uses the extended Euclidean algorithm to find the solution to ax = b mod n
    /// @param a    (int) positive known term in the above equation
    /// @param b    (int) positive congruent term in the above equation
    /// @param n    (int) modulus value of the equation 
    /// @return     (int) the solution x to the equation ax = b mod n
    /// @throw      if the modular inverse cannot be found, a const char* message notification is thrown
    /// -----------------------------------------------------------------------------------------------------------
    int modLinearEquationSolver(int a, int b, int n) const;

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
    int gcdExtended(int a, int b, int* x, int* y) const;

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief      solve a ^ b mod n fast using less multiplications
    /// @param a    (int) positive base of the equation
    /// @param b    (int) positive exponent of the equation
    /// @param n    (int) modulus value of the equation
    /// @return     (int) result of a ^ b mod n
    /// @note       relies on the idea that modding smaller parts gets same result
    /// @example    a^5 mod n = a^2 mod n * a^2 mod n * a mod n
    /// -----------------------------------------------------------------------------------------------------------
    int fastModExponentiation(int a, int b, int n) const;

public:
    /// -----------------------------------------------------------------------------------------------------------
    /// @brief constructor for the RSA class
    /// -----------------------------------------------------------------------------------------------------------
    RSA();
    ~RSA()=default;

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief  getter that returns the public key for external use
    /// @return (Key struct) returns the encryption key and number
    /// -----------------------------------------------------------------------------------------------------------
    const Key getPublicKey() { return publicKey; }

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief helper function to generate a new set of keys and primes 
    /// -----------------------------------------------------------------------------------------------------------
    void generateKeys();

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief              encrypts the given plaintext with the object's public key
    /// @param plaintext    (int) the plaintext to encrypt
    /// @return             (int) the ciphertext of the encryption
    /// -----------------------------------------------------------------------------------------------------------
    int encrypt(int plaintext) const;

    /// -----------------------------------------------------------------------------------------------------------
    /// @brief              decrypts the given ciphertext with the object's private key
    /// @param ciphertext   (int) the ciphertext to decrypt
    /// @return             (int) the plaintext of the decryption
    /// -----------------------------------------------------------------------------------------------------------
    int decrypt(int plaintext) const;
};

#endif 