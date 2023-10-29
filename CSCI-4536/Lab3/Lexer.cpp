#include "Lexer.hpp"

Lexer::
Lexer(string filename){
    inFile.open(filename);
    if (!inFile) throw "Error: Could not open input file!";

    outFile.open(filename + ".out");
    if (!outFile) throw "Error: Could not open output file!";

    outFile << "James Mok, Andrew Haller, Anusha Mandadam" << endl;
    outFile << "Lab 3: Forth Lexer" << endl;
    outFile << "Lexed File: " << filename << endl;
    outFile << "Comments: " << endl;
}

Lexer::
~Lexer(){
    inFile.close();
    outFile.close();
}

void Lexer::
doLex(){

}

ostream& Lexer::
print(ostream& out){
    return out;
}

void Lexer::
doToken(string name, TokenType type){
     if (map<string, Token>::iterator search = tokenMap.find(name); 
        search != tokenMap.end()){
            search->second.incrementRefCount();
     }
     else {
        // I could use auto here but I figured it would be teaching moment to write it out
        const pair<map<string, Token>::iterator, bool> ret = tokenMap.insert({name, Token(name, type)});
        if (!ret.second) throw "Error: tokenMap failed insert!";
        tokenString = "";
     }
}

void Lexer::
doStart(){
    switch(currentChar){
        case '\\':
            state = SLASH_PENDING;
            break;
        case '(':
            state = PAREN_PENDING;
            break;
        case ' ': 
            break;
        default:
            state = ACQUIRING_TOKEN;
            tokenString += currentChar;
            break;
    }
}