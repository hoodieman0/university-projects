#include "UnitTest-SDES.hpp"

/// ----------------------------------------------------------------------------
/// @brief check the SDES class against question 4a and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputA(){
    try{
        const unsigned int plaintext = 0b10111101; 
        const unsigned int key = 0b1010000010;
        const unsigned int ciphertext = 0b01110101;
        
        // create class with submission output on
        SDES cipher(key, true);
        const unsigned int resultCipher = cipher.encrypt(plaintext);
        if (resultCipher != ciphertext) throw "Returned cipher text is wrong!";

        const unsigned int resultPlain = cipher.decrypt(resultCipher);
        if (resultPlain != plaintext) throw "Returned plain text is wrong!";

    } catch(const char* txt) {
        cout << txt << endl; return 1;
    } catch (...) { return 1; }

    return 0;
}

/// ----------------------------------------------------------------------------
/// @brief check the SDES class against question 4b and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputB(){
    try{
        const unsigned int plaintext = 0b01110111; 
        const unsigned int key = 0b1101110111;
        const unsigned int ciphertext = 0b11001101;

        // create class with submission output on
        SDES cipher(key, true);
        const unsigned int resultCipher = cipher.encrypt(plaintext);
        if (resultCipher != ciphertext) throw "Returned cipher text is wrong!";

        const unsigned int resultPlain = cipher.decrypt(resultCipher);
        if (resultPlain != plaintext) throw "Returned plain text is wrong!";

    } catch(const char* txt) {
        cout << txt << endl; return 1;
    } catch (...) { return 1; }

    return 0;
}

/// ----------------------------------------------------------------------------
/// @brief check the SDES class against question 4c and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_InputC(){
    try{
        const unsigned int plaintext = 0b01110111; 
        const unsigned int key = 0b1101110111;
        const unsigned int ciphertext = 0b00000101;

        // create class with submission output on
        modSDES cipher(key, true);

        const unsigned int resultCipher = cipher.modEncrypt(plaintext);
        if (resultCipher != ciphertext) throw "Returned cipher text is wrong!";

        const unsigned int resultPlain = cipher.modDecrypt(resultCipher);
        if (resultPlain != plaintext) throw "Returned plain text is wrong!";
    } catch(const char* txt) {
        cout << txt << endl; return 1;
    } catch (...) { return 1; }

    return 0;
}

/// ----------------------------------------------------------------------------
/// @brief check the SDES class against question 4a and verify correctness
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
int UnitTest_RunHomework(){
    int points = 0;
    const int maxPoints = 30;

    cout << "Running homework tests for SDES class" << endl;
    cout << "------------------------------------------------------" << endl;

    cout << "Running Requirement - InputA..." << endl;
    if (UnitTest_InputA()) { cout << "Requirement - InputA -> Failed Test \u274c" << endl; }
    else { cout << "Requirement- InputA -> Passed Test \u2713" << endl; points += 10; }

    cout << "------------------------------------------------------" << endl;
    cout << endl;
    
    cout << "Running Requirement - InputB..." << endl;
    if (UnitTest_InputB()) { cout << "Requirement - InputB -> Failed Test \u274c" << endl; }
    else { cout << "Requirement- InputB -> Passed Test \u2713" << endl; points += 10; }

    cout << "------------------------------------------------------" << endl;
    cout << endl;
    
    cout << "Running Requirement - InputC..." << endl;
    if (UnitTest_InputC()) { cout << "Requirement - InputC -> Failed Test \u274c" << endl; }
    else { cout << "Requirement- InputC -> Passed Test \u2713" << endl; points += 10; }

    cout << "------------------------------------------------------" << endl;
    cout << endl;

    cout << "Estimated score on homework = " << points << "/" << maxPoints << endl;
    // Note: not really the accurate score but just a fun tracker

    return 0;
}

/// ----------------------------------------------------------------------------
/// @brief run all the unit tests for the SDES class
/// @return int 0 on pass, 1 on fail 
/// ----------------------------------------------------------------------------
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