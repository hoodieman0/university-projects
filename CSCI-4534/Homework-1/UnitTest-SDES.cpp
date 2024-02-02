#include "UnitTest-SDES.hpp"

/// @brief check the SDES class against question 4a and verify correctness
/// @return int 0 on pass, 1 on fail 
int UnitTest_InputA(){
    try{
        const unsigned int plaintext = 0b10111101; 
        const unsigned int key = 0b1010000010;
        const unsigned int ciphertext = 0b01110101;

        SDES cipher(key, true, true);
        const unsigned int resultCipher = cipher.encrypt(plaintext);
        if (resultCipher != ciphertext) throw "Returned cipher text is wrong!";

        const unsigned int resultPlain = cipher.decrypt(resultCipher);
        if (resultPlain != plaintext) throw "Returned plain text is wrong!";

    } catch(const char* txt) {
        cout << txt << endl; return 1;
    } catch (...) { return 1; }

    return 0;
}

/// @brief run all the unit tests for the SDES class
/// @return int 0 on pass, 1 on fail 
int UnitTest_RunAll(){
    int passed = 0, failed = 0;

    cout << "Running all unit tests for SDES class" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - InputA..." << endl;
    if (UnitTest_InputA()) { cout << "Unit Test - InputA -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - InputA -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - InputB..." << endl;
    if (UnitTest_InputB()) { cout << "Unit Test - InputB -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - InputB -> Passed Test \u2713" << endl; passed++; }

    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - InputC..." << endl;
    if (UnitTest_InputC()) { cout << "Unit Test - InputC -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - InputC -> Passed Test \u2713" << endl; passed++; }


    cout << "------------------------------------------------------" << endl;
    cout << "Finished running all tests" << endl;
    cout << "\u2713 Passed Tests: " << passed << endl;
    cout << "\u274c Failed Tests: " << failed << endl;

    return 0;
}