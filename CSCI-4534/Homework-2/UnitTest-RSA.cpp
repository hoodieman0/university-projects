#include "UnitTest-RSA.hpp"

/// ----------------------------------------------------------------------------
/// @brief verify class creation works
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RSACreation(){
    try {
        RSA cipher;
        const int plaintext = 88;
        // const int ciphertext = 11;

        const int resultCipher = cipher.encrypt(plaintext);
        cout << "Ciphertext: " << resultCipher << endl;
        const unsigned int resultPlain = cipher.decrypt(resultCipher);
        cout << "Plaintext: " << resultPlain << endl;

        // if (resultCipher != ciphertext) throw "Returned cipher text is wrong!";

        // const unsigned int resultPlain = cipher.decrypt(resultCipher);
        if (resultPlain != plaintext) throw "Returned plain text is wrong!";

    } catch(const char* txt) {
        cout << txt << endl; return 1;
    } catch (...) { return 1; }

    return 0;
}

int UnitTest_RSAExhaustive(){
    int passed = 0, failed = 0;
    for (int i = 0; i < TEST_RUNS; i++){
        if (UnitTest_RSACreation()) failed++;
        else passed++;
    }

    cout << "\u2713 Passed Tests: " << passed << endl;
    cout << "\u274c Failed Tests: " << failed << endl;

    return 0;
}

/// ----------------------------------------------------------------------------
/// @brief run all the unit tests for the SDES class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunAll(){
    int passed = 0, failed = 0;

    cout << "Running all unit tests for RSA class" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "Running Unit Test - RSA Creation..." << endl;
    if (UnitTest_RSACreation()) { cout << "Unit Test - RSA Creation -> Failed Test \u274c" << endl; failed++;}
    else { cout << "Unit Test - RSA Creation -> Passed Test \u2713" << endl; passed++; }


    cout << "------------------------------------------------------" << endl;
    cout << "Finished running all tests" << endl;
    cout << "\u2713 Passed Tests: " << passed << endl;
    cout << "\u274c Failed Tests: " << failed << endl;

    return 0;
}