#include "game.hpp"
#include "tools.hpp"

int main(){
    string filename;
    cout<<"Enter Filename: " <<endl;
    cin>>filename;
    Game obj(filename);
    obj.run();

    return 0;
}