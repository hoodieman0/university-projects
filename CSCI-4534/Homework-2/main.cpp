#include <chrono>
#include <iostream>
#include <iomanip>

#include "RSAAttacker.hpp"

using namespace std;

/// function for testing homework problems
void Problem(RSAAttacker& attack, Members info);

int main(){
    cout << "------------------------------------------------------" << endl;
    cout << "~ RSA Brute Force Attacker Program ~" << endl;

    // Blank initialization
    RSAAttacker attack(0, 0, 0);
    
    // formatted as public key, number, ciphertext
    // private key = 7, plaintext = 10, primes = 3 & 5, totient = 8
    Members q1 { 7, 15, 10 };

    // private key = 37, plaintext = 271, primes = 17 & 31, totient = 480
    Members q2 { 13, 527, 356 };

    // private key = 20477 11143, plaintext = 67, primes = 113 & 191, totient = 21280
    Members q3 { 53, 21583, 8567 };

    cout << "------------------------------------------------------" << endl;
    cout << "Running Problem 1..." << endl;
    cout << "------------------------------------------------------" << endl;

    Problem(attack, q1);

    cout << "------------------------------------------------------" << endl;
    cout << "Running Problem 2..." << endl;
    cout << "------------------------------------------------------" << endl;

    Problem(attack, q2);

    cout << "------------------------------------------------------" << endl;
    cout << "Running Problem 3..." << endl;
    cout << "------------------------------------------------------" << endl;

    Problem(attack, q3);

    cout << "------------------------------------------------------" << endl;
    cout << "~ End of Program ~" << endl;

    return 0;
}

/// @brief          a helper function to run both RSAAttacker functions on one problem set
/// @param attack   (RSAAttacker) any object that will get its values changed with info param
/// @param info     (struct Members) the specified public key, number, and ciphertext xtruct
void Problem(RSAAttacker& attack, Members info){
    // read in the information into the attacker
    attack.SetInfo(info);

    cout << "=========================" << endl;
    cout << "Ciphertext: " << info.ciphertext << endl;
    cout << "Public Key: " << info.encryptionKey << endl;
    cout << "Number:     " << info.number << endl;
    cout << "==========================" << endl;


    cout << "Running Attack One..." << endl;
    const auto start1 = chrono::high_resolution_clock::now();
    const int plaintext = attack.AttackOne();
    const auto end1 = chrono::high_resolution_clock::now();
    cout << "Plaintext: " << plaintext << endl;

    const std::chrono::duration<double> time1 = end1 - start1;
    const auto timeCast1 = chrono::duration_cast<chrono::microseconds>(end1 - start1);

    cout << "Time to complete AttackOne: " << timeCast1.count() << " microseconds\n" << endl;

    cout << "Running Attack Two..." << endl;
    const auto start2 = chrono::high_resolution_clock::now();
    const attackTwoReturn vals = attack.AttackTwo();
    const auto end2 = chrono::high_resolution_clock::now();

    cout << "Prime P:     " << vals.primeP << endl;
    cout << "Prime Q:     " << vals.primeQ << endl;
    cout << "Private Key: " << vals.privKey << endl;
    cout << "Plaintext:   " << vals.plaintext << endl;

    const auto timeCast2 = chrono::duration_cast<chrono::microseconds>(end2 - start2);

    cout << "Time to complete AttackTwo: " << timeCast2.count() << " microseconds\n" << endl;
}