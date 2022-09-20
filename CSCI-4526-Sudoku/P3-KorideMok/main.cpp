#include "game.hpp"
#include "tools.hpp"

//TODO MORE CTORS, MORE CONSTS AND STATICS

int main(){
    banner();

    string filename;
    cout<<"Enter Filename: " <<endl;
    cin>>filename;
    Game obj(filename);
    obj.run();

    bye();
}