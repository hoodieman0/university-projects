#include "Game-KorideMok.hpp"
#include "tools.hpp"

//TODO MORE CTORS, MORE CONSTS AND STATICS

int main(){
    banner();

    string filename;
    cout<<"Enter Filename: ";
    cin>>filename;
    cout << filename;
    Game obj(filename);
    obj.run();

    bye();
}