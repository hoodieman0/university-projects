#include "DSA.hpp"

/// -----------------------------------------------------------------------------------------------------------
/// @brief      solve a ^ b mod n fast using less multiplications
/// @param a    (int) positive base of the equation
/// @param b    (int) positive exponent of the equation
/// @param n    (int) modulus value of the equation
/// @return     (int) result of a ^ b mod n
/// @note       relies on the idea that modding smaller parts gets same result
/// @example    a^5 mod n = a^2 mod n * a^2 mod n * a mod n
/// -----------------------------------------------------------------------------------------------------------

int
fastModExponentiation(int a, int b, int n) {
    int result = 1;
    a = a % n;
    
    while (b > 0){
        if (b & 1) result = (result * a) % n;       // if b is odd, set the new result and mod it by n (result * [a mod n])
        b >>= 1;                                    // another a^2 mod n is added, divide exponent b by 2
        a = (a * a) % n;                            // a = a^2 mod n
    }

    return result;
}

DSA::
DSA(int p, int q, int h, int privateKey, int k) :
p(p), q(q), h(h), privateKey(privateKey), k(k) {
    g = fastModExponentiation(h, (p-1)/q, p);
    publicKey = fastModExponentiation(g, privateKey, p);
}

