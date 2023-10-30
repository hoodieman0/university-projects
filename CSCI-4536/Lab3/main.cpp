// TODO use const
#include "Lexer.hpp"

//Creats instance of Lexer, called doLex on instance
int main(){
    Lexer lex("circle.f");
    lex.doLex();
    // printing to the output file handled by doLex(0)

    return 0;
}
