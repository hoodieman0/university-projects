#include "Lexer.hpp"

Lexer::
Lexer(string filename) : state(STARTING), currentChar(' '), tokenString(""){
    inFile.open(filename);
    if (!inFile) throw "Error: Could not open input file!";

    outFile.open(filename + ".out");
    if (!outFile) throw "Error: Could not open output file!";

    outFile << "James Mok, Andrew Haller, Anusha Mandadam" << endl;
    outFile << "Lab 3: Forth Lexer" << endl;
    outFile << "Lexed File: " << filename << '\n' << endl;
    outFile << "Comments: " << endl;
}

Lexer::
~Lexer(){
    inFile.close();
    outFile.close();
}

// test to see if string is all numbers
bool Lexer::
isNumber(string s){
    for(int unsigned i = 0; i < s.size(); i++){ // what is the different between int unsigned and unsigned int?
        if (!isdigit(s[i])) return false;
    }
    return true;
}

void Lexer::
doLex(){
    while (true){ 
        inFile >> noskipws >> currentChar; // assuming that the last char of file is \n
        if (inFile.eof()){
            return;
        }
        switch(state){
            case STARTING:
                doStart();
                break;  
            case SLASH_PENDING: // TODO make helper function
                if (currentChar == ' ') state = ACQUIRING_SLASH;
                else state = ACQUIRING_TOKEN;
                break;
            case ACQUIRING_SLASH: // TODO make helper function
                while (true){
                    if (currentChar == '\n') break;
                    outFile << currentChar;
                    inFile >> currentChar;
                }
                outFile << currentChar; // adds the trailing \n
                state = STARTING;
                break;
            case PAREN_PENDING: // TODO make helper function
                if (currentChar == ' ') state = ACQUIRING_PAREN;
                else state = ACQUIRING_TOKEN;
                break;
            case ACQUIRING_PAREN: // TODO make helper function
                while (true){
                    if (currentChar == ')') break;
                    outFile << currentChar;
                    inFile >> currentChar;
                }
                outFile << endl; // adds a trailing \n
                state = STARTING;
            case ACQUIRING_TOKEN: // TODO make helper function
                while (true){
                    if (currentChar == ' ' || currentChar == '\n' || currentChar == 13) break;
                    tokenString += currentChar;
                    inFile >> noskipws >> currentChar;
                }

                if(isNumber(tokenString)){
                    doToken(tokenString, NUMBER);
                    state = STARTING;
                }
                else if(tokenString[0] == '.' && tokenString[1] == '\"'){ // TODO make helper function
                    doToken(tokenString, WORD);
                    state = ACQUIRING_STRING;
                }
                else {
                    doToken(tokenString, WORD);
                    state = STARTING;
                }

                break;
            case ACQUIRING_STRING: // TODO make helper function
                tokenString = "";
                while (true){
                    if (currentChar == '\"') break;
                    tokenString += currentChar;
                    inFile >> currentChar;
                }
                doToken(tokenString, STRING);
                state = STARTING;
                break;
            case DONE:
            default:
                break;
        }
    }
}

ostream& Lexer::
print(ostream& out){
    out << "Token Info" << endl;
    for(map<string, Token>::iterator itr = tokenMap.begin(); itr != tokenMap.end(); itr++){
        out << itr->second << endl;
        out << "===========================" << endl;
    }
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
     }
    tokenString = "";
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
        case '\n':
            doToken("\n", WORD);
            break;
        default:
            state = ACQUIRING_TOKEN;
            tokenString += currentChar;
            break;
    }
}