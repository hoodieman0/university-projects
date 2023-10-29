#ifndef LEXER_HPP
#define LEXER_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include "Types.hpp"
#include "Token.hpp"


using namespace std;



class Lexer {
private:
    StateType state;
    ifstream inFile;
    ofstream outFile;
    map<string, Token> tokenMap;
    char currentChar;
    string tokenString;
    // TokenType currentToken;

    bool isNumber(string s);

public:
    Lexer(string filename);
    ~Lexer();

    void doLex();
    ostream& print(ostream& out);
    void doToken(string name, TokenType type);
    void doStart();

};

#endif