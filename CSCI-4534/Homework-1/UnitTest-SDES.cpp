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

    } catch(const char* a) {
        cout << a << endl; return 1;
    } catch (...) { return 1; }

    return 0;
}