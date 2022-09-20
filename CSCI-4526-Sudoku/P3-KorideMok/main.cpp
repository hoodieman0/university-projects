#include "game.hpp"
#include "tools.hpp"

int main(){
    banner();

    string filename;
    cout<<"Enter Filename: " <<endl;
    cin>>filename;
    Game obj(filename);
    obj.run();

    bye();
}