#include "HillCipher.hpp"

HillCipher::
HillCipher(uint blockSize, Key key) : blockSize(blockSize), key(key){
    // check if block size different from key size
}

HillCipher::
HillCipher(uint blockSize, Block encryptionKey, Block decryptionKey) : blockSize(blockSize) {
    key = {
        encryptionKey,
        decryptionKey
    };
}

string HillCipher::
encrypt(string plaintext) const {
    string ciphertext;
    vector<Block> plaintextMatrix = stringToMatrixBlocks(plaintext);

    for (Block elem : plaintextMatrix){
        Block multi = matrixMultiplication(key.encryption, elem);
        for (uint i = 0; i < multi.matrix[0].size(); i++){
            ciphertext += multi.matrix[0][i] + 97;
        }
    }
    return ciphertext;
}

string HillCipher::
decrypt(string ciphertext) const {
    string plaintext;
    vector<Block> ciphertextMatrix = stringToMatrixBlocks(ciphertext);
    for (Block elem : ciphertextMatrix){
        Block multi = matrixMultiplication(key.decryption, elem);
        for (uint i = 0; i < multi.matrix[0].size(); i++){
            plaintext += multi.matrix[0][i] + 97;
        }
    }
    return plaintext;
}

vector<Block> HillCipher::
stringToMatrixBlocks(string input) const {
    vector<Block> resultBlocks; // stores plaintext blocks
    for (uint i = 0; i < input.size(); i += blockSize){
        vector<vector<uint>> matrix(1);
        vector<uint> column(blockSize);

        for (uint j = 0; j < blockSize; j++){
            if (i + j >= input.size()) column[j] = 122 - 97;   // pads with z
            else column[j] = input[i + j] - 97;
            column[j] = column[j] % DOMAIN_SIZE;
        }

        matrix[0] = column;
        resultBlocks.push_back(Block(matrix));
    }
    return resultBlocks;
}

// must be matrices of size (a x b) * (c x d) where b == c
Block HillCipher::
matrixMultiplication(Block first, Block second) const {
    // b != c
    if (first.matrix.size() != second.matrix[0].size()) throw "Invalid matrix multiplication";

    int resultRowSize = first.matrix[0].size(); // a
    int resultColSize = second.matrix.size(); // d
    vector<vector<uint>> resultMatrix(second.matrix.size(), vector<uint>(resultRowSize));
    for (int row = 0; row < resultRowSize; row++){
        for (int col = 0; col < resultColSize; col++){
            uint total = 0;
            for (uint i = 0; i < blockSize; i++){
                total += first.matrix[i][row] * second.matrix[col][i];
            }
            resultMatrix[col][row] = total % DOMAIN_SIZE;
        }
    }
    return Block(resultMatrix);
}

void HillCipher::
printMatrix(Block input) const {
    for (uint row = 0; row < input.matrix[0].size(); row++){
        for (uint col = 0; col < input.matrix.size(); col++){
            cout << input.matrix[col][row] << " ";
        }
        cout << endl;
    }
}