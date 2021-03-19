/*
GACHA Slot Machine

Author:: James Mok

Date Created:: 9 March 2021

Objective:: Successfully use templates and circular linked lists.
*/

#include "SlotMachine.hpp"
#include "CircularLinkedListTemp.hpp"

#include <iostream>

int main()
{
    std::cout << "~Gacha Ruins Your Life~" << endl;
    
    char arrayOne[10] = {'a','a','a','a','b','b','b','c','c','7'};
    char arrayTwo[10] = {'c','c','b','a','b','a','7','a','a','b'};
    char arrayThree[10] = {'b','a','b','a','b','c','a','a','c','7'};

    // SlotMachine<char>* gachaMachine;
    // std::cerr << "Creation Passed" << endl;
    // gachaMachine->Initialize(arrayOne, arrayTwo, arrayThree);
    // std::cerr << "Initialize Passed" << endl;
    // gachaMachine->Debug();
    // std::cerr << "Debug Passed" << endl;
    // std:: cerr << gachaMachine->Spin(gachaMachine->GetReelOne(), gachaMachine->GetReelTwo(), gachaMachine->GetReelThree());
    // std::cerr << "Spin Passed" <<endl;

    LinkedList<char>* reelOne;
    
    for (int i = 0; i < 10; i++)
    {
        reelOne->PutItem(arrayOne[i]);
        std::cout << "Putting " << arrayOne[i] << endl;
    }

    for (int i = 0; i < 10; i++)
    {
        std::cout << reelOne->GetNextItem();
    }

    // char input;
    // bool loop = true;
    // GameController Headhunting;

    // std::cout << "Spin the Gacha? (Y/N)" << endl;
    // cin >> input;

    // if (std::toupper(input) == 'Y')
    // {
    //     Headhunting.PlayGame(100);
    // }
    // else
    // {
    //     std::cout << "No Dice" << endl;
    // }

    std::cout << "\n~End of Program~";
}