#ifndef HILLCIPHER_HPP
#define HILLCIPHER_HPP

#define DOMAIN_SIZE 26 // 26 letters in the lowercase alphabet, a = 0

#include <vector>
#include <string>
#include <iostream>
using namespace std;

typedef unsigned int uint;

struct Block {
    vector<vector<uint>> matrix; // stores matrix of arbitrary size
    // matrix [col][row]
    Block(vector<vector<uint>> matrix) : matrix(matrix) { };
    Block()=default;
};

struct Key {
    Block encryption;
    Block decryption;
};

// strings should be all lowercase
class HillCipher {
    private:
        uint blockSize;
        Key key;

        vector<Block> stringToMatrixBlocks(string input) const;
        Block matrixMultiplication(Block first, Block second) const; // order matters
        void printMatrix(Block input) const;

    public:
        HillCipher(uint blockSize, Key key);
        HillCipher(uint blockSize, Block encryptionKey, Block decryptionKey);
        ~HillCipher()=default;

        string encrypt(string plaintext) const;
        string decrypt(string ciphertext) const;
};

#endif