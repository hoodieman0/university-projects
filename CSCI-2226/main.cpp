#include "Battle.hpp"
#include "MoveType.hpp"

#include <iostream>

int main()
{
    ActorType p1;
    ActorType p2;
    std::string input;

    std::cout << "\n\n~Welcome To A Casual Fight To The Death~\n\n";

    std::cout << "\nDo You Want To Play As A \"Knight\" or \"Ghost\"? (Default Knight)\n";
    std::cin >> input;

    if (input == "Ghost")
    {
        p1 = ActorType::Ghost;
        p2 = ActorType::Knight;
    }
    else
    {
        p1 = ActorType::Knight;
        p2 = ActorType::Ghost;
    }
    
    Battle* FightToTheDeath = new Battle(p1, p2);

    while (!FightToTheDeath->GetIsOver())
    {
        FightToTheDeath->Start();
    }

    std::cout << "\n\n~End Of Program~\n\n";
}