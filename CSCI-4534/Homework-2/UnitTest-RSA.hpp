#ifndef UNITTEST_RSA_HPP
#define UNITTEST_RSA_HPP

#define TEST_RUNS 100000

#include <iostream>
#include "RSA.hpp"

using namespace std;

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


int UnitTest_RSAExhaustive();

/// ----------------------------------------------------------------------------
/// @brief run all the unit tests for the RSA class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunAll();

#endif