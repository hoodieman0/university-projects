#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Types.hpp"
#include "Token.hpp"


using namespace std;


//outline of the lexer classs
class Lexer {
private:
    StateType state;
    ifstream inFile;
    ofstream outFile;
    map<string, Token> tokenMap;
    char currentChar;
    string tokenString;

    bool isNumber(string s) const;
    void doToken(string name, TokenType type);
    void doStart();

//class parameter and deconstructer and print statement
public:
    Lexer(string filename);
    ~Lexer();

    void doLex();
    ostream& print(ostream& out) const;


};

inline ostream& operator<<(ostream& out, Lexer& lx){
    return lx.print(out);
}

#endif
