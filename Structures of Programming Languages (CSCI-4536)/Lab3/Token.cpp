#include "Token.hpp"

//Sets Token parameters
Token::
Token(string name, TokenType type) : name(name), type(type), refCount(1) {
}

//Prints Tokens
ostream& Token::
print(ostream& out) const {
    out << "Token Name: '" << name << "' | Type: " << TokenTypeName[type] << " | Times Referenced: " << refCount;
    return out;
}
    
//Increments counter    
void Token::
incrementRefCount() {
    refCount++;
};
