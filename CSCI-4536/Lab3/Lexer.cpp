#include "Lexer.hpp"

Lexer::Lexer(string filename){
    inFile.open(filename);
    if (!inFile) throw "Error: Could not open input file!";

    outFile.open(filename + ".out");
    if (!outFile) throw "Error: Could not open output file!";

    outFile << "James Mok, Andrew Haller, Anusha Mandadam" << endl;
    outFile << "Lab 3: Forth Lexer" << endl;
    outFile << "Lexed File: " << filename << endl;
    outFile << "Comments: " << endl;
}

Lexer::~Lexer(){
    inFile.close();
    outFile.close();
}

void Lexer::doLex();
ostream& Lexer::print(ostream& out);
void Lexer::doToken(string name, TokenType type);
void Lexer::doStart();