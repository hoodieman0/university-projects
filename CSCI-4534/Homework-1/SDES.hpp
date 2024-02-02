#ifndef SDES_HPP
#define SDES_HPP

#include <string>

using namespace std;

class SDES {
  private:
    int keyOne;
    int keyTwo;
    // P10 -> SHIFT -> P8 -> keyOne
    // P10 -> SHIFT -> SHIFT-> P8 -> keyOne
    void KeyGen(unsigned int key);

  public:
    SDES(const unsigned int key);
    ~SDES() = default;

    // IP -> smallF w/ K1 -> SW -> smallF w/ K2 -> inverseIP 
    string encryption(const unsigned int plaintext);

    // IP -> smallF w/ K2 -> SW -> smallF w/ K1 -> inverseIP 
    string decryption(const unsigned int ciphertext);

    

    void IP();
    void inverseIP();
    void P10();
    void P8();
    void SW();
    void smallF();
    void F();
    void S0();

};

#endif