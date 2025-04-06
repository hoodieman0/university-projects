#ifndef UNITTEST_SDES_HPP
#define UNITTEST_SDES_HPP

#include <iostream>
#include "SDES.hpp"
#include "mod-SDES.hpp"

using namespace std;

/// ----------------------------------------------------------------------------
/// @brief check the SDES class against question 4a and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputA();

/// ----------------------------------------------------------------------------
/// @brief check the SDES class against question 4b and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputB();

/// ----------------------------------------------------------------------------
/// @brief check the SDES class against question 4c and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputC();

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