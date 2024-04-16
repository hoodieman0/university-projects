#ifndef UNITTEST_DSA_HPP
#define UNITTEST_DSA_HPP

#include <iostream>
#include "DSA.hpp"

using namespace std;

/// ----------------------------------------------------------------------------
/// @brief check the RSA class against the attacks and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunHomework();

int UnitTest_InputA();
int UnitTest_InputB();
int UnitTest_InputC();

/// ----------------------------------------------------------------------------
/// @brief run all the unit tests for the RSA class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunAll();

#endif