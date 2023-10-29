#include "Token.hpp"

Token::
Token(string name, TokenType type) : name(name), type(type), refCount(1) {
}

ostream& Token::
print(ostream& out){
    out << "Token Name: " << name << " | Type: " << TokenTypeName[type] << " | Times Referenced: " << refCount;
    return out;
}
    
    
void Token::
incrementRefCount() {
    refCount++;
};