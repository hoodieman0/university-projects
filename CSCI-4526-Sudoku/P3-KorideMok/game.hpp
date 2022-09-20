
#ifndef GAME_HPP
#define GAME_HPP
#include <fstream>
class Game{

    const char* Menu[6];
    // Board*
    int N;
    char GameType;
    std::ifstream ifs;
public:
    Game(std::string);
    void run();


};

#endif