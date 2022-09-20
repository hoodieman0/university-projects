#include "game.hpp"
#include <iostream>
#include <string>

int main(){
    std::string filename;
    std::cout<<"Enter filename"<<std::endl;
    std::cin>>filename;
    Game* obj;
    obj = new Game(filename);
    obj->run();

    return 0;
}