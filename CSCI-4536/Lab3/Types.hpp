#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>

using namespace std;

enum TokenType {WORD, NUMBER, STRING};
enum StateType {STARTING, DONE, ACQUIRINGTOKEN, ACQUIRINGCOMMENT, ACQUIRINGSTRING};

string TokenTypeName[3] = {"Word", "Number", "String"};

#endif