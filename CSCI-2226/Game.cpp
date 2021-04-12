#include "Game.hpp"

void Game::StartGame()
{
    ActorType p1;
    ActorType p2;
    std::string input;


    std::cout << "\nDo You Want To Play As A \"Knight\" or \"Ghost\"? (Default Knight)\n";
    getline(std::cin, input);

    if (input == "Ghost")
    {
        std::cout << "\nChoice: Ghost\n";
        p1 = ActorType::Ghost;
    }
    else
    {
        std::cout << "\nChoice: Knight\n";
        p1 = ActorType::Knight;
    }

    std::cout << "\nWhat Should The CPU Play As? \"Knight\" or \"Ghost\"? (Default Ghost)\n";
    getline(std::cin, input);

    if (input == "Knight")
    {
        std::cout << "\nChoice: Knight\n";
        p2 = ActorType::Knight;
    }
    else
    {
        std::cout << "\nChoice: Ghost\n";
        p2 = ActorType::Ghost;
    }
    
    FightToTheDeath = new Battle(p1, p2);    
}

void Game::GameLoop()
{
    std::cout<< "\nStarting Battle Loop\n";
    FightToTheDeath->Start(); //start has its own loop
    std::cout<<"\nGame Over!\n";
}