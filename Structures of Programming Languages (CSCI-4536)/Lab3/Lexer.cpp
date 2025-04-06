#include "Lexer.hpp"

//Throws errors if cant open file
Lexer::
Lexer(string filename) : state(STARTING), currentChar(' '), tokenString(""){
    inFile.open(filename);
    if (!inFile) throw "Error: Could not open input file!";

    outFile.open(filename + ".output");
    if (!outFile) throw "Error: Could not open output file!";

    outFile << "James Mok, Andrew Haller, Anusha Mandadam" << endl;
    outFile << "Lab 3: Forth Lexer" << endl;
    outFile << "Lexed File: " << filename << '\n' << endl;
    outFile << "===========================================================================" << endl;
    outFile << "~Comments~\n" << endl;
}

//closes file when deconstructing
Lexer::
~Lexer(){
    inFile.close();
    outFile.close();
}

// test to see if string is all numbers
bool Lexer::
isNumber(string s) const{
    for(int unsigned i = 0; i < s.size(); i++){ // what is the different between int unsigned and unsigned int?
        if (!isdigit(s[i])) return false;
    }
    return true;
}

//calls doLex on every character unless its a /n in which cases its eof
void Lexer::
doLex(){
    while (true){ 
        inFile >> noskipws >> currentChar; // assuming that the last char of file is \n
        if (inFile.eof()){
            outFile << "===========================================================================" << endl;
            outFile << *this;
            return;
        }

        //state is STARTING by default
        //Depending on the input char read, the state changes
        switch(state){
            case STARTING:
                doStart();
                break;  

            //checks for whitespace and changes state
            case SLASH_PENDING: // TODO make helper function
                if (currentChar == ' ') state = ACQUIRING_SLASH;
                else state = ACQUIRING_TOKEN;
                break;

            //Reads line to output file
            //Changes state to start once it reaches a newline char
            case ACQUIRING_SLASH: // TODO make helper function
                while (true){
                    if (currentChar == '\n') break;
                    outFile << currentChar;
                    inFile >> currentChar;
                }
                outFile << currentChar; // adds the trailing \n
                state = STARTING;
                break;
            
            //changes state to acquirinParen or acquiringToken
            case PAREN_PENDING: // TODO make helper function
                if (currentChar == ' ') state = ACQUIRING_PAREN;
                else state = ACQUIRING_TOKEN;
                break;

            //Reads in char's till a ')' is found
            case ACQUIRING_PAREN: // TODO make helper function
                while (true){
                    if (currentChar == ')') break;
                    outFile << currentChar;
                    inFile >> currentChar;
                }
                outFile << endl; // adds a trailing \n
                state = STARTING;

            //main case, keeps adding to the token string until breaks
            //checks if the tokenString is a number or word
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
            
            //Creates a tokenString
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

//prints out map
ostream& Lexer::
print(ostream& out) const {
    out << "~Token Info~\n" << endl;
    for(map<string, Token>::const_iterator itr = tokenMap.begin(); itr != tokenMap.end(); itr++){
        out << itr->second << endl;
        out << endl;
    }
    return out;
}

//searches the map to see if the Token already exists, if it does +1. If not, add to map
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

//Checks current char and changes state depending
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
        case '\n':
        case 13:
            break;
        default:
            state = ACQUIRING_TOKEN;
            tokenString += currentChar;
            break;
    }
}
