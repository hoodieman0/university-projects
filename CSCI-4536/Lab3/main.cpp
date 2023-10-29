// TODO use const
#include "Lexer.hpp"

int main(){
    Lexer lex("circle.f");
    lex.doLex();
    
    ofstream ofile("test.txt");
    ofile << lex << endl;
    ofile.close();

    return 0;
}