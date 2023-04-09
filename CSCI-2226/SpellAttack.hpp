#pragma once

#include "BattleMove.hpp"

class SpellAttack : public BattleMove
{
    private:
        int damageAmount;
    public:
        SpellAttack(Actor*, Actor*);
        void Execute();
        void Undo();
};