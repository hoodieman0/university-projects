// TODO use const
#include "Lexer.hpp"

int main(){
    Lexer lex("circle.f");
    lex.doLex();
    // printing to the output file handled by doLex(0)

    return 0;
}