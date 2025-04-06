#ifndef CRYPTOGRAPHY_HPP
#define CRYPTOGRAPHY_HPP

using namespace std;

/// -----------------------------------------------------------------------------------------------------------
/// @brief      helper function to calculate modular inverse, ax = 1 mod n from modLinearEquationSolver
/// @param a    (int) positive known term in the above equation
/// @param n    (int) modulus value of the equation 
/// @return     (int) modular inverse of a mod n 
/// @throw      if the modular inverse cannot be found, a const char* message notification is thrown
/// -----------------------------------------------------------------------------------------------------------
int modInverse(int a, int n); 

/// -----------------------------------------------------------------------------------------------------------
/// @brief      uses the extended Euclidean algorithm to find the solution to ax = b mod n
/// @param a    (int) positive known term in the above equation
/// @param b    (int) positive congruent term in the above equation
/// @param n    (int) modulus value of the equation 
/// @return     (int) the solution x to the equation ax = b mod n
/// @throw      if the modular inverse cannot be found, a const char* message notification is thrown
/// -----------------------------------------------------------------------------------------------------------
int modLinearEquationSolver(int a, int b, int n);

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
int gcdExtended(int a, int b, int* x, int* y);

/// -----------------------------------------------------------------------------------------------------------
/// @brief      solve a ^ b mod n fast using less multiplications
/// @param a    (int) positive base of the equation
/// @param b    (int) positive exponent of the equation
/// @param n    (int) modulus value of the equation
/// @return     (int) result of a ^ b mod n
/// @note       relies on the idea that modding smaller parts gets same result
/// @example    a^5 mod n = a^2 mod n * a^2 mod n * a mod n
/// -----------------------------------------------------------------------------------------------------------
int fastModExponentiation(int a, int b, int n);

#endif