#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <iostream>
#include "Types.hpp"

using namespace std;

class Token {
private:
    string name;
    TokenType type;
    unsigned short refCount;

public:
    Token(string name, TokenType type);
    ostream& print(ostream& out) const;
    void incrementRefCount();
};

inline ostream& operator<<(ostream& out, const Token& tk){
    return tk.print(out);
}

#endif