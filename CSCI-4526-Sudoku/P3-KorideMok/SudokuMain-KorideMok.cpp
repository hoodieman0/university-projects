#include "Game-KorideMok.hpp"
#include "tools.hpp"

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