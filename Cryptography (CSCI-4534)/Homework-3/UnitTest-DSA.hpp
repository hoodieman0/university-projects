#ifndef UNITTEST_DSA_HPP
#define UNITTEST_DSA_HPP

#include <iostream>
#include "DSA.hpp"

using namespace std;

/// ----------------------------------------------------------------------------
/// @brief see if input 1 on homework works for DSA class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputA();

/// ----------------------------------------------------------------------------
/// @brief see if input 2 on homework works for DSA class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputB();

/// ----------------------------------------------------------------------------
/// @brief see if custom inputs work for DSA class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputC();

/// ----------------------------------------------------------------------------
/// @brief run all the unit tests for the DSA class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunAll();

#endif