#ifndef CRYPTOGRAPHY_HPP
#define CRYPTOGRAPHY_HPP

using namespace std;

int modInverse(int a, int n); 
int modLinearEquationSolver(int a, int b, int n);
int gcdExtended(int a, int b, int* x, int* y);
int fastModExponentiation(int a, int b, int n);

#endif