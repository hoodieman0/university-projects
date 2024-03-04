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
/// @brief check the RSA class against the attacks and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunHomework();

/// ----------------------------------------------------------------------------
/// @brief verify RSA class creation works
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RSACreation();

/// ----------------------------------------------------------------------------
/// @brief run all the unit tests for the SDES class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunAll();

#endif