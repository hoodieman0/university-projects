#include "Game-KorideMok.hpp"
#include "tools.hpp"

int main(){
    banner();
    //TODO file name as command line arg
    string filename;
    cout<<"Enter Filename: ";
    cin>>filename;
    cout << filename;
    Game obj(filename);
    obj.run();

    bye();
}