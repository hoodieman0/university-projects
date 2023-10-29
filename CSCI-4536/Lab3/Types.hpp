#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>

using namespace std;

enum TokenType {WORD, NUMBER, STRING};
enum StateType {STARTING, DONE, ACQUIRING_TOKEN, SLASH_PENDING, ACQUIRING_SLASH, PAREN_PENDING, ACQUIRING_PAREN, ACQUIRING_STRING};

string TokenTypeName[4] = {"Word", "Number", "String"};

#endif