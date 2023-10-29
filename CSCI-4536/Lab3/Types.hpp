#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>

using namespace std;

enum TokenType {WORD, NUMBER, STRING, EMPTY};
enum StateType {STARTING, DONE, ACQUIRINGTOKEN, ACQUIRINGCOMMENT, ACQUIRINGSTRING};

string TokenTypeName[4] = {"Word", "Number", "String", "Empty"};

#endif