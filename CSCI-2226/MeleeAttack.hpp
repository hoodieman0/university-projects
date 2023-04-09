#pragma once

#include "BattleMove.hpp"

class MeleeAttack : public BattleMove
{
    private:
        int damageAmount;
    public:
        MeleeAttack(Actor*, Actor*);
        void Execute();
        void Undo();
};