#include "RSAAttacker.hpp"

/// -----------------------------------------------------------------------------------------------------------
/// @brief              main constructor for RSAAttacker helper class
/// @param eKey         (int) encryption key/private key of RSA
/// @param number       (int) calculated number N of RSA
/// @param ciphertext   (int) valid ciphertext of RSA derived from m ^ eKey mod number (m is unknown to class)
/// @note               this class does not check for validness of inputs
/// -----------------------------------------------------------------------------------------------------------
RSAAttacker::
RSAAttacker(int eKey, int number, int ciphertext) {
    info.encryptionKey = eKey;
    info.number = number;
    info.ciphertext = ciphertext;
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief          constructor for RSAAttacker helper class that allows assignment using Members struct
/// @param info     (struct Members) values needed for attacker, see RSAAttacker(int, int, int)
/// @note           this class does not check for validness of inputs
/// -----------------------------------------------------------------------------------------------------------
RSAAttacker::
RSAAttacker(Members info) : info(info) {}

/// -----------------------------------------------------------------------------------------------------------
/// @brief  run through all possible values of m until [m ^ eKey mod number = ciphertext] is found
/// @return (int) plaintext associated with the inputted ciphertext from info
/// -----------------------------------------------------------------------------------------------------------
int RSAAttacker::
AttackOne(){
    int guess = 0, m = 0;

    while (guess != info.ciphertext)
        guess = fastModExponentiation(++m, info.encryptionKey, info.number);
    
    return m;
}

/// -----------------------------------------------------------------------------------------------------------
/// @brief  factor inputted info.number into its two primes and get plaintext by calculating private key from them
/// @return (struct secondVal) following calculated values via RSA algorithm: { (int) prime P, (int) prime Q, (int) private key, (int) plaintext }
/// -----------------------------------------------------------------------------------------------------------
secondVal RSAAttacker::
AttackTwo(){
    // calculate the two prime factors (naively)
    int p, q;
    for (int i = 1; i < info.number; i++){
        if (info.number % i == 0){
            p = i; q = info.number / p;
        }
    }
    // calculate the totient of the primes
    int totient = eulerTotient(p, q);

    // calculate the private key by getting the inverse of eKey mod totient
    int privateKey = modInverse(info.encryptionKey, totient);

    // calculate plaintext from c ^ dKey mod number
    int m = fastModExponentiation(info.ciphertext, privateKey, info.number);

    return secondVal { p, q, privateKey, m };
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
int RSAAttacker::
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

/// -----------------------------------------------------------------------------------------------------------
/// @brief      helper function to calculate modular inverse, ax = 1 mod n
/// @param a    (int) positive known term in the above equation
/// @param n    (int) modulus value of the equation 
/// @return     (int) modular inverse of a mod n 
/// @throw      if the modular inverse cannot be found, a const char* message notification is thrown
/// -----------------------------------------------------------------------------------------------------------
int RSAAttacker::
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
int RSAAttacker::
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
/// @note       remainder = ax + by = GCD(a, b)
/// @param a    (int) the first term to find the GCD with
/// @param b    (int) the second term to find the GCD with
/// @param x    (int*) return parameter to return Bezout coefficient x
/// @param y    (int*) return parameter to return Bezout coefficient y
/// @return     (int) the GCD of a & b, as well as Bezout coefficients in x & y
/// @cite       https://en.wikipedia.org/wiki/Extended_Euclidean_algorithm#Pseudocode
/// @date       4 Mar 2024
/// -----------------------------------------------------------------------------------------------------------
int RSAAttacker::
gcdExtended(int a, int b, int* x, int* y) const{
    int remainder   = a, newRemainder   = b;   
    int bezoutX     = 1, bezoutXCalc    = 0;
    int bezoutY     = 0, bezoutYCalc    = 1;
    int quotient    = 0, temp           = 0;

    while (newRemainder != 0){                                  // while 
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