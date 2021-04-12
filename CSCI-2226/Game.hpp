#pragma once

#include "Battle.hpp"
#include "Actor.hpp"

#include <iostream>

class Game
{
    private:
        Battle* FightToTheDeath;

    public:
        void StartGame();
        void GameLoop();
};