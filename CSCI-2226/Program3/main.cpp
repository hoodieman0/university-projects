#include "Game.hpp"

#include <iostream>

int main()
{
    std::cout << "\n\n~Welcome To A Casual Fight To The Death~\n\n";

    //create and start game
    Game* game = new Game();
    game->StartGame();
    
    game->GameLoop();

    std::cout << "\n\n~End Of Program~\n\n";
}