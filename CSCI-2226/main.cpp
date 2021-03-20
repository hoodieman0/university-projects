/*
GACHA Slot Machine

Author:: James Mok

Date Created:: 9 March 2021

Objective:: Successfully use templates and circular linked lists to create a slot machine.

Side Note:: LMD stands for Lungmen Dollar, it's a reference to the Arknights mobile game.
*/

#include "GameController.hpp"

#include <iostream>

// how much money the player should start with
#define STARTING_BALANCE 100 

int main()
{
    std::cout << "\n~Gacha Ruins Your Life~" << std::endl;

    char input;
    GameController Headhunting; //creates a new game instance

    if (STARTING_BALANCE <= 0) //checks if the balance is a positive number
    {
        std::cout << "\nYou Do Not Have LMD. Go Print Some More.\n\n";
        exit(1);
    }

    std::cout << "\nSpin The Gacha? (Y/N)" << std::endl;
    std::cin >> input;

    if (std::toupper(input) == 'Y')
    {
        Headhunting.PlayGame(STARTING_BALANCE); //starts the game with the balance
    }
    else
    {
        std::cout << "No Dice" << std::endl;
    }

    std::cout << "\n\n~End of Program~\n\n";
}