#include <iostream>
#include "HillCipher.hpp"


void UnitTest(int blockSize, Key key, string plaintext);
bool isAlphaString(string input);
string toLowerString(string input);

int main(){

    vector<vector<uint>> firstEK = {{1, 1}, {2, 3}};
    vector<vector<uint>> firstDK = {{3, 25}, {24, 1}};
    string firstPlaintext = "hi";
    
    vector<vector<uint>> secondEK = {{1, 1}, {2, 3}};
    vector<vector<uint>> secondDK = {{3, 25}, {24, 1}};
    string secondPlaintext = "HelloWorl";

    vector<vector<uint>> thirdEK = {{6, 13, 20}, {24, 16, 17}, {1, 10, 15}};
    vector<vector<uint>> thirdDK = {{8, 21, 21}, {5, 8, 12}, {10 , 21, 8}};
    string thirdPlaintext = "ACTONTHEGOODNESS";

    UnitTest( 2,
        Key {  
            Block(firstEK),
            Block(firstDK)
        },
        firstPlaintext
    );

    cout << "-----------------------------------------------------------------------" << endl;
    UnitTest( 2,
        Key {  
            Block(secondEK),
            Block(secondDK)
        },
        secondPlaintext
    );

    cout << "--------------------------" << endl;
    UnitTest( 3,
        Key {  
            Block(thirdEK),
            Block(thirdDK)
        },
        thirdPlaintext
    );

}

void UnitTest(int blockSize, Key key, string plaintext){
    if (!isAlphaString(plaintext)) throw "plaintext contains non-letters";
    plaintext = toLowerString(plaintext);
    HillCipher cipher(blockSize, key);
    string resultCipher = cipher.encrypt(plaintext);
    string resultPlain = cipher.decrypt(resultCipher);
    cout << "The plaintext is:            " << plaintext << endl;
    cout << "The resulting ciphertext is: " << resultCipher << endl;
    cout << "The resulting plaintext is:  " << resultPlain << endl;

}

bool isAlphaString(string input){
    for (char c : input){
        if (!isalpha(c)) return false;
    }
    return true;
}

string toLowerString(string input){
    if (!isAlphaString(input)) throw "string contains non-letters";
    string result;
    for (char c : input){
        result += tolower(c);
    }
    return result;
}