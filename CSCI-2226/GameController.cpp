#include "GameController.hpp"
#include "SlotMachine.hpp"

#include <iostream>

void GameController::PlayGame(int balance)
{
    char input;

    //slot machine reels
    char arrayOne[10] = {'a','a','a','a','b','b','b','c','c','7'};
    char arrayTwo[10] = {'c','c','b','a','b','a','7','a','a','b'};
    char arrayThree[10] = {'b','a','b','a','b','c','a','a','c','7'};

    SlotMachine<char>* gachaMachine; //creates slot machine

    std::cout << "Your Balance Is Currently $" << balance << endl;
    if (balance == 0) //checks if there is money in the account
    {
        std::cout << "Balance Is Zero. No Dice";
        return;
    }

    balance -= 1;
    
    gachaMachine->Initialize(arrayOne, arrayTwo, arrayThree);
    balance = CheckPayoutTable(balance, gachaMachine->Spin(gachaMachine->GetReelOne(), gachaMachine->GetReelTwo(), gachaMachine->GetReelThree()));
    
    std::cout << "Play Again? (Y/N)" << endl; //play again recursion
    cin >> input;
    if (std::toupper(input) == 'Y')
    {
        PlayGame(balance);
    }
    else
    {
        std::cout << "No Dice. Your final balance was $" << balance;
        return;
    }
}

int GameController::CheckPayoutTable(int balance, std::string reelReal)
{
    int index = -1;

    std::string combinations[4] = {"aaa","bbb","ccc","777"};
    for (int i = 0; i < 4; i++)
    {
        if (combinations[i] == reelReal)
        {
            index = i;
        }
    }

    switch(index)
    {
        case 0: return balance += 6;
        case 1: return balance += 15;
        case 2: return balance += 50;
        case 3: 
            std::cout<< "\n***JACKPOT***" << endl;
            return balance += 500; ;
        default:
            std::cout << "Sorry, No Matches. Go Pray to RNGesus.";
            return balance;
    }
}