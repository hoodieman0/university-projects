#include "UnitTest-DSA.hpp"

/// ----------------------------------------------------------------------------
/// @brief run all the unit tests for the SDES class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunAll(){
    int passed = 0, failed = 0;

    cout << "Running all unit tests for RSA class" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - Input A..." << endl;
    if (UnitTest_InputA()) { cout << "Unit Test - Input A -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - Input A -> Passed Test \u2713" << endl; passed++; }

    cout << "Running Unit Test - Input B..." << endl;
    if (UnitTest_InputB()) { cout << "Unit Test - Input B -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - Input B -> Passed Test \u2713" << endl; passed++; }

    cout << "Running Unit Test - Input C..." << endl;
    if (UnitTest_InputC()) { cout << "Unit Test - Input C -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - Input C -> Passed Test \u2713" << endl; passed++; }


    cout << "------------------------------------------------------" << endl;
    cout << "Finished running all tests" << endl;
    cout << "\u2713 Passed Tests: " << passed << endl;
    cout << "\u274c Failed Tests: " << failed << endl;

    return 0;
}