#ifndef RSA_ATTACKER_HPP
#define RSA_ATTACKER_HPP

/// @brief internal data members of RSAAttacker class
struct Members {
    int encryptionKey;  // public key of RSA
    int number;         // number N of RSA
    int ciphertext;     // ciphertext from m ^ eKey mod number
};

/// @brief return value for AttackTwo to aggregate data and return one item
struct attackTwoReturn {
    int primeP;     // calculated primes from RSA
    int primeQ;
    int privKey;    // private key/decryption key associated with RSA encryption key
    int plaintext;  // calculated message m where m = c ^ dKey mod number
};


class RSAAttacker{
private:
    Members info;   // aggregated data members, see Members struct

public:
    /// ---------------------------------------------------------------------------------
    /// @brief              main constructor for RSAAttacker helper class
    /// @param eKey         (int) encryption key/private key of RSA
    /// @param number       (int) calculated number N of RSA
    /// @param ciphertext   (int) valid ciphertext of RSA derived from m ^ eKey mod number (m is unknown to class)
    /// @note               this class does not check for validness of inputs
    /// ---------------------------------------------------------------------------------
    RSAAttacker(int eKey, int number, int ciphertext);

    /// ---------------------------------------------------------------------------------
    /// @brief          constructor for RSAAttacker helper class that allows assignment using Members struct
    /// @param info     (struct Members) values needed for attacker, see RSAAttacker(int, int, int)
    /// @note           this class does not check for validness of inputs
    /// ---------------------------------------------------------------------------------
    RSAAttacker(Members info);

    ~RSAAttacker() = default;

    /// ---------------------------------------------------------------------------------
    /// @brief          setter to change out internal information
    /// @param info     (struct Members) struct values to change to
    /// ---------------------------------------------------------------------------------
    void SetInfo(Members info) { this->info = info; }

    /// ---------------------------------------------------------------------------------
    /// @brief      calculates the Euler totient of two prime numbers
    /// @param p    (int) a prime number 
    /// @param q    (int) a prime number
    /// @return     (int) totient of primes p and q
    /// ---------------------------------------------------------------------------------
    int eulerTotient(int p, int q) const { return (p-1)*(q-1); }

    /// ---------------------------------------------------------------------------------
    /// @brief  run through all possible values of m until [m ^ eKey mod number = ciphertext] is found
    /// @return (int) plaintext associated with the inputted ciphertext from info
    /// ---------------------------------------------------------------------------------
    int AttackOne();

    /// ---------------------------------------------------------------------------------
    /// @brief  factor inputted info.number into its two primes and get plaintext by calculating private key from them
    /// @return (struct attackTwoReturn) following calculated values via RSA algorithm: { (int) prime P, (int) prime Q, (int) private key, (int) plaintext }
    /// ---------------------------------------------------------------------------------
    attackTwoReturn AttackTwo();

    /// ---------------------------------------------------------------------------------
    /// @brief      solve a ^ b mod n fast using less multiplications
    /// @param a    (int) positive base of the equation
    /// @param b    (int) positive exponent of the equation
    /// @param n    (int) modulus value of the equation
    /// @return     (int) result of a ^ b mod n
    /// ---------------------------------------------------------------------------------
    int fastModExponentiation(int a, int b, int n) const;

    /// ---------------------------------------------------------------------------------
    /// @brief      helper function to calculate modular inverse, ax = 1 mod n
    /// @param a    (int) positive known term in the above equation
    /// @param n    (int) modulus value of the equation 
    /// @return     (int) modular inverse of a mod n 
    /// @throw      if the modular inverse cannot be found, a const char* message notification is thrown
    /// ---------------------------------------------------------------------------------
    int modInverse(int a, int n) const;

    /// ---------------------------------------------------------------------------------
    /// @brief      uses the extended Euclidean algorithm to find the solution to ax = b mod n
    /// @param a    (int) positive known term in the above equation
    /// @param b    (int) positive congruent term in the above equation
    /// @param n    (int) modulus value of the equation 
    /// @return     (int) the solution x to the equation ax = b mod n
    /// @throw      if the modular inverse cannot be found, a const char* message notification is thrown
    /// ---------------------------------------------------------------------------------
    int modLinearEquationSolver(int a, int b, int n) const;

    /// ---------------------------------------------------------------------------------
    /// @brief      the extended Euclidean algorithm to find the greatest common denominator
    /// @note       remainder = ax + by = GCD(a, b)
    /// @param a    (int) the first term to find the GCD with
    /// @param b    (int) the second term to find the GCD with
    /// @param x    (int*) return parameter to return Bezout coefficient x
    /// @param y    (int*) return parameter to return Bezout coefficient y
    /// @return     (int) the GCD of a & b, as well as Bezout coefficients in x & y
    /// ---------------------------------------------------------------------------------
    int gcdExtended(int a, int b, int* x, int* y) const;
};

#endif