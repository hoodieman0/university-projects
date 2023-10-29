#include "Lexer.hpp"

Lexer::Lexer(string filename);
Lexer::~Lexer();

void Lexer::doLex();
ostream& Lexer::print(ostream& out);
void Lexer::doToken(string name, TokenType type);
void Lexer::doStart();