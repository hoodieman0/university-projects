#ifndef UNITTEST_RSA_HPP
#define UNITTEST_RSA_HPP

#include <iostream>
#include "RSA.hpp"

using namespace std;

/// ----------------------------------------------------------------------------
/// @brief break the RSA class against attack 1 and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_AttackOne();

/// ----------------------------------------------------------------------------
/// @brief break the RSA class against attack 2 and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_AttackTwo();

/// ----------------------------------------------------------------------------
/// @brief check the SDES class against question 4a and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunHomework();

/// ----------------------------------------------------------------------------
/// @brief run all the unit tests for the SDES class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunAll();

#endif