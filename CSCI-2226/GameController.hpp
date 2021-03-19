#ifndef GameController_hpp
#define GameController_hpp

#include <string>

class GameController
{
    private:
        int balance;
    public:
        void PlayGame(int);
        int CheckPayoutTable(int, std::string);
};

#endif