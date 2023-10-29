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

    bool isNumber(string s);
    void doToken(string name, TokenType type);
    void doStart();

public:
    Lexer(string filename);
    ~Lexer();

    void doLex();
    ostream& print(ostream& out);


};

inline ostream& operator<<(ostream& out, Lexer& lx){
    return lx.print(out);
}

#endif