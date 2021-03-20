#ifndef GameController_hpp
#define GameController_hpp

#include "SlotMachine.hpp"

#include <string>

class GameController
{
    private:
        int balance;

        //slot machine reels
        char arrayOne[10] = {'a','a','a','a','b','b','b','c','c','7'};
        char arrayTwo[10] = {'c','c','b','a','b','a','7','a','a','b'};
        char arrayThree[10] = {'b','a','7','b','a','b','c','a','a','c',};

        //creates slot machine
        SlotMachine<char>* gachaMachine = new SlotMachine<char>(arrayOne, arrayTwo, arrayThree); 

    public:
        void PlayGame(int);
        int CheckPayoutTable(int, std::string);
};

#endif