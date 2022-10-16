#include "Game-KorideMok.hpp"
#include "tools.hpp"

// argv[1] is the file name used in Game class
int main(int argc, char * const argv[]){
    banner();

    if(argc != 2){ fatal("!Incorrect Amount Of Arguments!"); }

    Game obj(argv[1]);
    obj.run();

    bye();
}