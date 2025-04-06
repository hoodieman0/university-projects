#include "GameController.hpp"
#include "SlotMachine.hpp"

#include <iostream>

void GameController::PlayGame(int balance)
{
    char input;

    std::cout << "\nYour Balance Is Currently $" << balance << " LMD." << std::endl;

    //checks if there is money in the account, and the amount deducted is not greater than the balance
    if (balance <= 0 || balance - 1 < 0) 
    {
        std::cout << "Balance Is Zero. No Dice";
        return;
    }

    balance -= 1;
    
    //since each reel is private within the SlotMachine class, the spin function must be called like this
    balance = CheckPayoutTable(balance, gachaMachine->Spin(gachaMachine->GetReelOne(), gachaMachine->GetReelTwo(), gachaMachine->GetReelThree()));
    
    //second balance check, for edge case if the balace goes from 1 to 0 and nothing is won.
    if (balance <= 0) 
    {
        std::cout << "\nBalance Is Zero. No Dice";
        return;
    }

    //play again recursion loop
    std::cout << "\nPlay Again? (Y/N)" << std::endl; 
    std::cin >> input;
    if (std::toupper(input) == 'Y')
    {
        PlayGame(balance);
    }
    else
    {
        std::cout << "\nNo Dice. Your final balance was $" << balance << " LMD.";
        return;
    }
}

int GameController::CheckPayoutTable(int balance, std::string reelReal)
{
    int index = -1; //uses default case

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
        case 0: balance += 6; std::cout << "You Won $6 LMD!\nYour Current Balance Is Now $" << balance << " LMD." << std::endl; return balance;
        case 1: balance += 15; std::cout << "You Won $15 LMD!\nYour Current Balance Is Now $" << balance << " LMD." << std::endl; return balance;
        case 2: balance += 50; std::cout << "You Won $50 LMD!\nYour Current Balance Is Now $" << balance << " LMD." << std::endl; return balance;
        case 3: 
            balance += 500;
            std::cout<< "*************\n***JACKPOT***\n*************\n\nYou Won $500 LMD!\nYour Current Balance Is Now: " << balance << std::endl;
            return balance;
        default:
            std::cout << "Sorry, No Matches. Go Pray To RNGesus." << std::endl;
            std::cout << "Your Current Balance Is Now $" << balance << " LMD." << std::endl;
            return balance;
    }
}