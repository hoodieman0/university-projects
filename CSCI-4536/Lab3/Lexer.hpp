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
    map<string, Token> symbolTable;
    char cursor;
    TokenType curToken;

public:
    Lexer(string filename);
    ~Lexer();

    void doLex();
    ostream& print(ostream& out);
    void doToken(string name, TokenType type);
    void doStart();

};

#endif