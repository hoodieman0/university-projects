#include "SwordAttack.hpp"

SwordAttack::SwordAttack(Actor* attacker, Actor* target)
{
    self = attacker;
    other = target;
}

void SwordAttack::Execute()
{
    damageAmount = battleMoveHelper.randInt(0, 20);
    other->Hit(damageAmount);
}

void SwordAttack::Undo()
{
    other->Heal(damageAmount);
}