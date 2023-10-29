#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include "Types.hpp"

using namespace std;

class Token {
private:
    string name;
    TokenType type;
    unsigned short refCount;

public:
    Token(string name, TokenType type);
    ofstream& print(ofstream& out);
    void incrementRefCount();
};

#endif